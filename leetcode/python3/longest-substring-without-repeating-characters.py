#
# @lc app=leetcode id=3 lang=python3
#
# [3] Longest Substring Without Repeating Characters
#
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # store the character we have already seen it.
        used = {}
        # start: start of the substring index
        start = maxlen = 0
        for i, c in enumerate(s):
            # if it's there and the start index is <= that index
            if c in used and start <= used[c]:
                # update the start to the last seen duplicate's index + 1
                start = used[c] + 1
            else:
                # if it's not in the used map, we can calculate the 
                # longest substring seen so far. Just take the current
                # index minus start index.
                maxlen = max(maxlen, i-start+1)
            used[c] = i
        return maxlen


