#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
    tg1632_hw2_q7.py
    Taimur Ghani
    29 September 2017
    This program finds the first
    instance of a 1 in a list
    recursively as well as iteratively.
"""

def findChangeRecur(lst01, lo=0, hi=None):
    if (hi is None):
        hi = len(lst01)-1 
    mid = lo + (hi - lo) // 2
    if (lst01[lo] == 1):
        return lo
    if (lst01[hi] != 1):
        return ("No 1s in the list")
    check = lst01[mid]
    if (check == 1):
        return findChange(lst01, lo, mid-1)
    else:
        return findChange(lst01, mid+1, hi)

def findChangeIter(lst):
    if lst[0] == 1:
        return 0
    lo = 0
    hi = len(lst)-1
    while lo < hi:
        mid = (lo+hi)//2
        if (lst[mid] == 1 and lst[mid-1] == 0):
            return mid
        elif (lst[mid] == 0 and lst[mid+1]==1):
                return mid+1
        else:
            if (lst[mid] == 0):
                lo = mid
            else:
                hi = mid
    return None
        

   
    
        
