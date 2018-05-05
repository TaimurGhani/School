#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
    tg1632_hw1_q3.py
    Taimur Ghani
    22 September 2017
    
"""
n =5

#part a function
def sumSquares(n):
    totalSum = 0
    for i in range(n):
        totalSum += (i**2)
    return totalSum
print(sumSquares(n))
 
#part b command
totalSum = sum([x**2 for x in range(n)])
print(totalSum)
print()

#part c function
def sumOddSquares(n):
    totalSum = 0
    for i in range(n):
        if (i % 2 == 1):
            totalSum += (i**2)
    return totalSum
print(sumOddSquares(n))

#part d command
totalSum = sum([x**2 for x in range(n) if (x % 2 == 1)])
print(totalSum)
