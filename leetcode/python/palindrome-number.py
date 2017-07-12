# I think this problem is meanless

class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        if x == 0:
            return True
        
        tmp = x
        y = 0
        while x:
            y = y*10 + x%10
            x = x/10
            
        if y == tmp:
            return True
        else:
            return False
        