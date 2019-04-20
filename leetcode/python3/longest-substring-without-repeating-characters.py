#
# @lc app=leetcode id=3 lang=python3
#
# [3] Longest Substring Without Repeating Characters
#
# https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#
# algorithms
# Medium (28.21%)
# Total Accepted:    881.2K
# Total Submissions: 3.1M
# Testcase Example:  '"abcabcbb"'
#
# Given a string, find the length of the longest substring without repeating
# characters.
# 
# 
# Example 1:
# 
# 
# Input: "abcabcbb"
# Output: 3 
# Explanation: The answer is "abc", with the length of 3. 
# 
# 
# 
# Example 2:
# 
# 
# Input: "bbbbb"
# Output: 1
# Explanation: The answer is "b", with the length of 1.
# 
# 
# 
# Example 3:
# 
# 
# Input: "pwwkew"
# Output: 3
# Explanation: The answer is "wke", with the length of 3. 
# ⁠            Note that the answer must be a substring, "pwke" is a
# subsequence and not a substring.
# 
# 
# 
# 
#
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        d = dict()
        maxlen = start = 0
        for i, c in enumerate(s):
            index = d.get(c, None)
            if index is not None and start <= index:
                start = index + 1
            else:
                maxlen = max(maxlen, i-start+1)
            d[c] = i
        return maxlen

