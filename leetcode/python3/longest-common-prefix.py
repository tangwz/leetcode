#
# @lc app=leetcode id=14 lang=python3
#
# [14] Longest Common Prefix
#
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        prefix = strs[0]
        if not prefix:
            return ""
        for i in range(1, len(strs)):
            j = 0
            for s in strs[i]:
                if j < len(prefix) and s == prefix[j]:
                    j += 1
                else:
                    break
            if j == 0:
                return ""
            prefix = prefix[:j]
        return prefix

