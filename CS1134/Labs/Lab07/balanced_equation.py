#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Oct 20 11:46:45 2017

@author: taimur
"""

def balanced_equation(string_input):
    openBraces = "({["
    closeBraces = ")}]"
    stack = []
    for char in string_input:
        if char in openBraces:
            stack.append(char)
        if char in closeBraces:
            if (len(stack) == 0):
                return False
            elif (stack[-1] != openBraces[closeBraces.index(char)]):
                return False
    return True

s = "{()}"
print(balanced_equation(s))