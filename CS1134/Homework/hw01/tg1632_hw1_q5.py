#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
    tg1632_hw1_q5.py
    Taimur Ghani
    22 September 2017
    Write a generator for the
    Fibonacci Sequence.
"""
def fibs(n):
    a, = 1, 1
    for i in range(n):
        yield a
        a, b = b, a+b

for curr in fibs(8):
    print(curr)
    
