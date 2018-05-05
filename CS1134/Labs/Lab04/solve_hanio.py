#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Sep 29 13:12:25 2017

@author: taimur
"""

def solve_hanio(n, frm, to, extra):
    if (n>0):
        solve_hanio(n-1, frm, extra, to)
        print("move " + frm + " to " + to)
        solve_hanio(n-1, extra, to, extra)
        
print (solve_hanio(3, 'A', 'C', 'B'))
    