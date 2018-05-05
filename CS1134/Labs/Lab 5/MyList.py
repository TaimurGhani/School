#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Oct  6 13:07:53 2017

@author: taimur
"""
import ctypes

class MyList:
    
    def __init__(self):
        self.size = 0
        self.capacity = 1
        self.data = self.makeArray(self.capacity)
    
    def makeArray(self, capacity):
        return (capacity * ctypes.py_object)()
    
    def __len__(self):
        return self.size
    
    def append(self, val):
        if (self.size == self.capacity):
            self.resize(2*self.capacity)
        self.data[self.size] = val
        self.size += 1
        
    def resize(self, newCap):
        newData = self.makeArray(newCap)
        for index in range(self.capacity):
            newData[index] = self.data[index]
        self.capacity = newCap
        self.data = newData
        
    def __setitem__(self, index, value):
        self.data[index] = value
    
    def __getitem__(self, index):
        return self.data[index]
    
    def __str__(self):
        result = [] 
        for i in range(len(self)-1):
           result.append(self.data[i]) 
        result = " ".join(result)
        return (result)
    
    def __add__(self, other):
        output = MyList()
        for i in range (len(self.data-1)):
            print(i)
            output.append(i)
        for i in range (len(other.data-1)):
            print(i)
            output.append(i)
        return output
    
   
            
        
            