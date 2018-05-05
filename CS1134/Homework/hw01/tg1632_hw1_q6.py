#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
    tg1632_hw1_q6.py
    Taimur Ghani
    22 September 2017
    
"""
class Vector:
    def __init__(self, d):
        if (isinstance(d, int)):
            self.coords = [0]*d
        else:
           self.coords = d
       
    def __len__(self):
        return len(self.coords)
    
    def __getitem__(self, j):
        return self.coords[j]
    
    def __setitem__(self, j, val):
        self.coords[j] = val
    
    def __add__(self, other):
        if (len(self) != len(other)):
            raise ValueError("dimensions must agree")
        result = Vector(len(self))
        for j in range(len(self)):
            result[j] = self[j] + other[j]
        return result
    
    def __eq__(self, other):
        return self.coords == other.coords
    
    def __ne__(self, other):
        return not(self == other)
    
    def __str__(self):
        return '<' + str(self.coords)[1:-1] + '>'
    
    def __repr__(self):
        return str(self)
    
    def __sub__(self, other):
        if (len(self) != len(other)):
            raise ValueError("dimensions must agree")
        result = Vector(len(self))
        for j in range(len(self)):
            result[j] = self[j] - other[j]
        return result
    
    def __neg__(self):
        result = Vector(len(self))
        for j in range (len(self)):
            result[j] = -1 * self[j]
        return result
    
    def __mul__(self, other):
       
        if (isinstance(other, int)):
            result = Vector(len(self))
            for j in range (len(self)):
                result[j] = self[j] * other
            return result
        else:
            if (len(self) != len(other)):
                raise ValueError("dimensions must agree")
            result = 0
            for j in range(len(self)):
                result += self[j] * other[j]
        return result
        
    
    def __rmul__(self, other):
        result = Vector(len(self))
        for j in range (len(self)):
            result[j] = self[j] * other
        return result
    