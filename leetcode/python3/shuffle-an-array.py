#
# @lc app=leetcode id=384 lang=python
#
# [384] Shuffle an Array
#
class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.array = nums
        self.original = list(nums)     

    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        self.array = self.original
        self.original = list(self.original)
        return self.array

    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        aux = list(self.array)

        for idx in range(len(self.array)):
            remove_idx = random.randrange(len(aux))
            self.array[idx] = aux.pop(remove_idx)

        return self.array


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()

