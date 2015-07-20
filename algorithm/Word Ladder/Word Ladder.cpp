class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        if(beginWord == endWord){
            return 0;
        }
        unordered_map<string, int> len;
        len[beginWord] = 1;//路径长度
        queue<string> q;
        //bfs
        for(q.push(beginWord); !q.empty(); q.pop()){//将起点加入队列，如果队列不同，则取出队首
            string word = q.front();
            int step = len[word] + 1;
            for(int i = 0; i < word.length(); ++i){
                for(int c = 'a'; c <= 'z'; ++c){
                   if(word[i] != c){
                        char temp = word[i];
                        word[i] = c;
                        if((wordDict.find(word) != wordDict.end()) && (len.find(word) == len.end())){
                            if(word == endWord){
                                return step;
                            }
                            q.push(word);
                            len.insert(make_pair(word, step));
                        }
                        word[i] = temp;
                   }
                }
            }
        }
        return 0;
    }
};