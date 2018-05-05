#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
    tg1632_hw2_q5.py
    Taimur Ghani
    29 September 2017
    This program puts all of the odd 
    numbers at the front of a given list
    and puts all of the even numbers in 
    the back.
"""

def split_parity(lst):
    ind = 0
    for i in range(len(lst)):
        if (lst[i] % 2 == 1):
            lst[ind], lst[i] = lst[i], lst[ind]
            ind += 1
    return lst

def main():
    test = [1, 2, 3, 4]
    print (split_parity(test))

main()
