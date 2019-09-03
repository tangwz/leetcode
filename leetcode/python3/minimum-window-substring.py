#
# @lc app=leetcode id=76 lang=python3
#
# [76] Minimum Window Substring
#
import collections

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        d = collections.defaultdict(int)
        for c in t:
            d[c] += 1
        counter = len(d)
        length = float('inf')
        begin = end = 0
        head = 0
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
                if end - begin < length:
                    length = end - begin
                    head = begin
                begin += 1
            
        if length == float('inf'): return ''
        return s[head:head+length]

