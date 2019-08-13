#
# @lc app=leetcode id=20 lang=python3
#
# [20] Valid Parentheses
#
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for c in s:
            if c in ['(', '[', '{']:
                stack.append(c)
            else:
                if not stack:
                    return False
                top = stack.pop()
                if c == ')':
                    if top != '(':
                        return False
                elif c == ']':
                    if top != '[':
                        return False
                else:
                    if top != '{':
                        return False
        return not bool(stack)


