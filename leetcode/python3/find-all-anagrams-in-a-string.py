#
# @lc app=leetcode id=438 lang=python3
#
# [438] Find All Anagrams in a String
#
import collections
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        ans = []
        d = collections.defaultdict(int)
        for c in p:
            d[c] += 1
        begin = end = 0
        counter = len(d)
        while end < len(s):
            c = s[end]

            if c in d:
                d[c] -= 1
                if d[c] == 0:
                    counter -= 1
            end += 1

            while counter == 0:
                tmp = s[begin]
                if tmp in d:
                    d[tmp] += 1
                    if d[tmp] > 0:
                        counter += 1
                if end - begin == len(p):
                    ans.append(begin)
                begin += 1
        return ans

