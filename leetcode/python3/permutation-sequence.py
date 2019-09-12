#
# @lc app=leetcode id=60 lang=python3
#
# [60] Permutation Sequence
#
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        numbers = [i for i in range(1, n+1)]
        permutation = ''
        k -= 1
        while n > 0:
            n -= 1
            index, k = k // self.factorial(n), k % self.factorial(n)
            permutation += str(numbers[index])
            numbers.remove(numbers[index])
        return permutation


    def factorial(self, n):
        ans = 1
        while n >= 1:
            ans *= n
            n -= 1
        return ans

