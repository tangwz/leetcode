# -*- coding: utf-8 -*-


class Solution(object):
    """ We can think a line of zigzag pattern is an item of a list.
        And the result of zigzag string is the join of list. So we
        sequentially generated the zigzag list and join it. The time
        complexity is O(n).
    """
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        step = (numRows == 1) - 1
        l = [''] * numRows
        i = 0
        for c in s:
            if i == 0 or i == numRows - 1:
                step = - step
            l[i] += c
            i += step
        return ''.join(l)


if __name__ == '__main__':
    test_str1 = 'PAYPALISHIRING'

    s = Solution()
    assert s.convert(test_str1, 3) == 'PAHNAPLSIIGYIR'