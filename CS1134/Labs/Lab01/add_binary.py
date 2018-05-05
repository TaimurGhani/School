# -*- coding: utf-8 -*-
"""
    Taimur Ghani
    QuestionOne.py
    8 September 2017
    This program will create a fucntion that is passed through
    two binary numbers and will return the sum of these two
    binary numbers as another binary number.
"""
import math

def add_binary(num1_str, num2_str):
    finalSum = bin(int(num1_str, 2) + int(num2_str, 2))
    print(finalSum[2:]) 
        
add_binary("111","1")