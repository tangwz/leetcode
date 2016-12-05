# coding: utf-8

import time
import json
import requests

USERNAME = ''
PASSWORD = ''
REPO = 'https://github.com/tangwz/leetcode'

class QuizItem(object):
    def __init__(self, data):
        self.id = int(data['id'])
        self.title = data['title']
        self.url = data['url']
        self.acceptance = data['acceptance']
        self.difficulty = data['difficulty']
        self.lock = data['lock']
        self.sample_code = None
        self.pass_status = None

    def __repr__(self):
        return '<Quiz: {id}-{title}({difficulty})-{pass_status}>'.format(
            id=self.id, title=self.title, difficulty=self.difficulty, pass_status=self.pass_status)


class Leetcode(object):

    def __init__(self):
        self._items = []
        self._base_url = 'https://leetcode.com'
        self._session = requests.Session()
        self._cookies = None
        self._is_login = False

    def login(self):
        """
            Maybe need login someday.
        """
        login_url = self._base_url + '/accounts/login/'

        self._session.get(login_url)
        token = self._session.cookies['csrftoken']
        print 'token: ', token
        login_data = {
            'csrfmiddlewaretoken': token,
            'login': USERNAME,
            'password': PASSWORD
        }
        self._session.post(login_url, headers={'Referer': login_url}, data=login_data)

        if not self._session.cookies.get('PHPSESSID'):
            raise Exception('Login Error')

        self._cookies = dict(self._session.cookies)
        self._is_login = True

        return self

    def load(self):
        api_url = self._base_url + '/api/problems/database/'

        # if not self._is_login:
        #     self.login()

        r = self._session.get(api_url)
        assert r.status_code == 200
        rst = json.loads(r.text)

        self._items = list(self._parse_items(rst))
        self._items.reverse()

    def _parse_items(self, json_data):
        difficulty = {1: "Easy", 2: "Medium", 3: "Hard"}
        for quiz in json_data['stat_status_pairs']:
            if quiz['stat']['question__hide']:
                continue
            data = {}
            data['title'] = quiz['stat']['question__title_slug']
            data['id'] = quiz['stat']['question_id']
            data['lock'] = not json_data['is_paid'] and quiz['paid_only']
            data['difficulty'] = difficulty[quiz['difficulty']['level']]
            data['favorite'] = quiz['is_favor']
            data['acceptance'] = "%.1f%%" % (float(quiz['stat']['total_acs']) * 100 / float(quiz['stat']['total_submitted']))
            data['url'] = '{base}/problems/{title}'.format(base=self._base_url,
                                                           title=quiz['stat']['question__title_slug'])
            data['pass'] = quiz['status']
            item = QuizItem(data)
            yield item

    def write_leetcode_generate(self):
        md = '''# :pencil2: Leetcode Generation.
Update time:  {tm}

Auto created by [leetcode_generate](https://github.com/tangwz/leetcode)

If you have any question, please give me an [issue]({repo}/issues).

If you are loving solving problems in leetcode Database, please contact me to enjoy it together!

(Notes: :lock: means you need to buy a book from Leetcode to unlock the problem)

| # | Title | Source Code | Difficulty |
|:---:|:---:|:---:|:---:|'''.format(tm=time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(time.time())),
                                          repo=REPO)

        md += '\n'
        for item in self._items:
            if item.lock:
                language = ':lock:'
            else:
                language = ''

            md += '|{id}|[{title}]({url})|{language}|{difficulty}|\n'.format(id=item.id, title=item.title,
                                                                                       url=item.url, language=language,
                                                                                       difficulty=item.difficulty)
        with open('Database.md', 'w') as f:
            f.write(md)


def main():
    leetcode = Leetcode()
    leetcode.load()
    leetcode.write_leetcode_generate()

if __name__ == '__main__':
    main()