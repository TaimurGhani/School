#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Sep 22 12:04:27 2017

@author: taimur
"""

def move_zeroes(nums):
    for index in range(len(nums)-1,-1,-1):
        if (nums[index] == 0):
            nums = nums[:index] + nums[index+1:] + [0]
    return nums