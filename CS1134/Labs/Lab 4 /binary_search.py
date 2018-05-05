#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Sep 29 13:06:03 2017

@author: taimur
"""

def binary_search(srt_lst, val, low=0, high=None):
    if (high is None):
        high = len(srt_lst)-1
    if (high < low):
        return None
    mid = high + (low - high)//2
    if (srt_lst[mid] == val):
        return mid
    elif (srt_lst[mid] > val):
        high = mid-1 
        return binary_search(srt_lst, val, low, high)
    else:
        low = mid +1 
        return binary_search(srt_lst, val, low, high)
            
print (binary_search([1, 2, 3, 4], 6))