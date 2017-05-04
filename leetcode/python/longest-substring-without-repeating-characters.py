# coding: utf-8

class Solution(object):
    """
        Store the word appeared in a dict. Then we can know the duplicated char's index.
        And we can keep the maxiumn length according to the dict.

        Time complexity : O(n)
        Space complexity: O(n)
    """
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        been = {}
        maxlen = start = 0

        for i in range(len(s)):
            index = been.get(s[i], None)
            if index is not None and start <= index:
                start = index + 1
            else:
                maxlen = max(maxlen, i - start + 1)
            been[s[i]] = i
        return maxlen


if __name__ == '__main__':
    test_case1 = 'abcabcbb'
    test_case2 = 'bbbbb'
    test_case3 = 'pwwkew'
    test_case4 = 'dvdf'

    s = Solution()
    assert s.lengthOfLongestSubstring(test_case1) == 3
    assert s.lengthOfLongestSubstring(test_case2) == 1
    assert s.lengthOfLongestSubstring(test_case3) == 3
    assert s.lengthOfLongestSubstring(test_case4) == 3
