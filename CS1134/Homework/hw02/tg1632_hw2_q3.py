#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
    tg1632_hw2_q3.py
    Taimur Ghani
    29 September 2017
    A generator that yields all
    of the factors of a given 
    number, num. 
"""

def factors(num):
    for i in range(1, int(num**0.5)+1):
        if (num%i == 0):
            yield i
    for i in range(int(num**0.5)-1, 0, -1):
        if (num%i == 0):
            yield (num//i)
    
for i in factors(100):
     print(i)