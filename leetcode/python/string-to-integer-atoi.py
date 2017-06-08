# -*- coding: utf-8 -*-
import re


class Solution(object):
    """ Maybe we can check the item of string one by one. But if we use python
        we can do it gracefully by regex. But I don't agree to leetcode answer
        when result is bigger than MAX_INT or less than MIN_INT.I don't understand
        what this mean?I think should return a None or raise it?
    """
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        str = str.strip()
        str = re.findall('^[+\-]?\d+', str)
        try:
            res = int(''.join(str))
            INT_MAX = 2147483647
            INT_MIN = -2147483648
            if res > INT_MAX:
                return INT_MAX
            if res < INT_MIN:
                return INT_MIN
            return res
        except:
            return 0
