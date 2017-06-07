# -*- coding: utf-8 -*-


class Solution(object):
    """ It's simple to use python to reverse a string, so we just reverse the string
        and convert it to int.
    """
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        s = cmp(x, 0)
        r = int(repr(s*x)[::-1])
        return s * r * (r < 2**31)


if __name__ == '__main__':
    test1 = 123
    test2 = -123

    s = Solution()
    assert s.reverse(test1) == 321
    assert s.reverse(test2) == -321
