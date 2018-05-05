#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Oct 26 22:21:38 2017

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

class Queue:
    def __init__(self):
        self.input = ArrayStack()
        self.output = ArrayStack()

    def enqueue(self, elem):
        self.input.push(elem)

    def dequeue(self):
        if (len(self.output) == 0):
            for i in range(len(self.input)):
                self.output.push(self.input.pop()) 
        return self.output.pop()
    
    def is_empty(self):
        return (self.input.is_empty() & self.output.is_empty())
    
    def front(self):
        if (self.is_empty()):
            raise Empty("Stack is empty")
        else:
            if (len(self.output) == 0):
                return self.input.data[0]
            else:
                return self.output.data[-1]
    
        

