#
# @lc app=leetcode id=204 lang=python
#
# [204] Count Primes
#
class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        # count = 0
        # for i in range(2, n):
        #     for j in range(2, i):
        #         if i % j == 0:
        #             break
        #     else:
        #         count += 1
        # return count
        if n < 3:
            return 0
        output = [1] * n
        output[0], output[1] = 0, 0
        for i in range(2, int(n**0.5) + 1):
            if output[i] == 1:
                output[i*i:n:i] = [0] * len(output[i*i:n:i])
        return sum(output)

