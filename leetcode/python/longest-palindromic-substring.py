# -*- coding: utf-8 -*-

class Solution(object):
    """ We use a simple way to find the palindromic string from begin
        to end, and store the longest string. But this way need time
        complexity O(n2).
    """
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return ''
        if len(s) == 1:
            return s
        res = ""
        for i in xrange(len(s)):
            res = max(self.helper(s, i, i), self.helper(s, i, i + 1), res, key=len)
        return res

    def helper(self, s, left, right):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return s[left+1:right]


if __name__ == '__main__':
    test1 = 'babad'
    test2 = 'cbbd'

    s = Solution()
    assert s.longestPalindrome(test1) in ('aba', 'bab')
    assert s.longestPalindrome(test2) == 'bb'