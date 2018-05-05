#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
    tg1632_hw2_q4.py
    Taimur Ghani
    29 September 2017
    This programs approximates e using
    the infinite sequence that defines it.
    It does approximates it using n amount 
    of terms from the sequence.
"""

def e_approx(n):
    div = 1
    approx = 1
    for i in range(n):
        approx += 1/div
        div*=(div+1)
    return approx


def main():
    for n in range(15):
        curr_approx = e_approx(n)
        approx_str = "{:.15f}".format(curr_approx)
        print("n =", n, "Approximation:", approx_str)
        
main()   