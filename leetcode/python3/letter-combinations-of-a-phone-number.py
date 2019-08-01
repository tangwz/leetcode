#
# @lc app=leetcode id=17 lang=python
#
# [17] Letter Combinations of a Phone Number
#
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        phone = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl',
             '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
        ans = []
        def f(tmp, chars):
            if not chars:
                ans.append(tmp)
            else:
                for c in phone[chars[0]]:
                    f(tmp+c, chars[1:])
        if digits:
            f('', digits)
        return ans

