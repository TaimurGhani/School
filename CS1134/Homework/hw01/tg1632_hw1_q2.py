#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
    tg1632_hw1_q2.py
    Taimur Ghani
    22 September 2017
    A function that does left 
    shift and right shift.
"""
#function declaration
def shift(lst, k, move = None):
    if (move is None or move=="Left"):
        for i in range(k):
            for i in range(len(lst)-1):  
                lst[i], lst[i+1]= lst[i+1], lst[i]
    elif (move == "right"):
        for i in range(k):
            for i in range(len(lst)-1, 0, -1):  
                lst[i], lst[i-1]= lst[i-1], lst[i]
    
    return lst


            

