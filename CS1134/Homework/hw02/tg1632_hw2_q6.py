#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
    tg1632_hw2_q6.py
    Taimur Ghani
    29 September 2017
    This program finds two numbers
    in a given list that add up to 
    some target value.
"""

def two_sum(srt_lst, target):
    start = 0
    end = len(srt_lst)-1
    while (start != end):
        if (srt_lst[start] + srt_lst[end] == target):
            return (start, end)
        elif (srt_lst[start] + srt_lst[end] > target):
            end += -1
        else:
            start += 1