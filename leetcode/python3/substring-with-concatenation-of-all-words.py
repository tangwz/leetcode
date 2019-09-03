#
# @lc app=leetcode id=30 lang=python3
#
# [30] Substring with Concatenation of All Words
#
import collections

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not words:
            return []
        ans = []
        d = collections.defaultdict(int)
        for word in words:
            d[word] += 1
        wl = len(words[0])
        for i in range(wl):
            begin, counter = i, 0
            sub = collections.defaultdict(int)
            for j in range(i, len(s)-wl+1, wl):
                word = s[j:j+wl]
                # valid word
                if word in d:
                    sub[word] += 1
                    counter += 1
                    while sub[word] > d[word]:
                        sub[s[begin:begin+wl]] -= 1
                        begin += wl
                        counter -= 1
                    if counter == len(words):
                        ans.append(begin)
                else:
                    begin = j + wl
                    sub = collections.defaultdict(int)
                    counter = 0
        return ans



