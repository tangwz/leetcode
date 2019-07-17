#
# @lc app=leetcode id=49 lang=python3
#
# [49] Group Anagrams
#
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        """
        # 按出现的字符个数，组合到一起
        ans = collections.defaultdict(list)
        for s in strs:
            count = [0] * 26
            for c in s:
                count[ord(c)-ord('a')] += 1
            ans[tuple(count)].append(s)
        return list(ans.values())
        """
        # 当排序后字符串相同时，组合到一起
        d = dict()
        for s in strs:
            k = ''.join(sorted(s))
            if k in d:
                d[k].append(s)
            else:
                d[k] = [s,]
        ans = []
        for _, v in d.items():
            ans.append(v)
        return ans



