#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Sep 29 13:00:44 2017

@author: taimur
"""

def decimal_to_binary(input_int):
    if (input_int//2 == 0):
        return input_int
    else:
        return (str(input_int%2) + str(decimal_to_binary(input_int//2)))[::-1]
    
print (decimal_to_binary(6))