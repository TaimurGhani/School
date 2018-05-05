#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Sep 29 12:51:43 2017

@author: taimur
"""

def is_palindrome(input_str, low = 0, high = None):
    if (high is None):
        high = len(input_str)-1
    if (low > high):
        return True
    elif (input_str[low] == input_str[high]):
        low += 1
        high -= 1
        return is_palindrome(input_str, low, high)
    else :
      return False
    
print (is_palindrome("kayak"))