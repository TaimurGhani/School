#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Oct 27 20:00:19 2017

@author: taimur
"""

class Empty(Exception):
    pass

class ArrayStack:
    def __init__(self):
        self.data = []

    def __len__(self):
        return len(self.data)

    def is_empty(self):
        return len(self) == 0

    def push(self, val):
        self.data.append(val)

    def top(self):
        if (self.is_empty()):
            raise Empty("Stack is empty")
        return self.data[-1]

    def pop(self):
        if (self.is_empty()):
            raise Empty("Stack is empty")
        return self.data.pop()


class MaxStack:
    
    def __init__(self):
        self.stack = ArrayStack()
        self.maxVal = None
    
    def is_empty(self):
        return self.stack.is_empty()
    
    def __len__(self):
        return len(self.stack)
    
    def push(self, val):
        if(self.maxVal is None or val > self.maxVal):
            self.maxVal = val
        self.stack.push((val, self.maxVal)) 
        
    
    def top(self):
        if(self.is_empty()):
            raise Empty("Stack is empty")
        return self.stack.top()[0]       
    
    def pop(self):
        if(self.is_empty()):
            raise Empty("Stack is empty")
        x = self.stack.top()[0]   
        self.stack.pop()
        return x
        
    def max(self):
        if(self.is_empty()):
            raise Empty("Stack is empty")
        return self.stack.top()[1]
        







    
    
            
            
            
            
            
            
            
            
    
