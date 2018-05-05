#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Oct 20 12:03:17 2017

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
    
class ArrayDequeue:
    def __init__(self):
        self.data = [None] * 10
        self.numOfElems = 0
        self.front = 0
    
    def __len__(self):
        return len(self.data)
    
    def is_empty(self):
        return (len(self.data) == 0)
    
    def first(self):
        return self.data[self.front]
    
    def last(self):
        return self.data[(self.front+self.numOfElems-1)%(len(self.data))]
    
    def add_first(self, elem):
        if (self.numOfElems == len(self.data)):
            self.resize(2*len(self.data))
        self.front = (self.front-1)%len(self.data)
        self.data[self.front] = elem
        self.numOfElems += 1
        
        
    def add_last(self, elem):
        if (self.numOfElems == len(self.data)):
            self.resize(2*len(self.data))
        self.data[(self.front+self.numOfElems)%len(self.data)] = elem
        self.numOfElems += 1
        
    def delete_first(self):
        ret = self.data[self.front]
        self.data[self.front] = None
        self.front += 1
        self.numOfElems -= 1
        if (self.numOfElems < len(self.data) // 4):
            self.resize(len(self.data) // 2)
        return ret
        
        
    def delete_last(self):
        ret = self.data[(self.front+self.numOfElems-1)%(len(self.data))]
        self.data[(self.front+self.numOfElems-1)%(len(self.data))] = None
        self.numOfElems -= 1
        return ret
        
    def resize(self, new_cap):
        old_data = self.data
        self.data = [None] * new_cap
        old_ind = self.front
        for new_ind in range(self.numOfElems):
            self.data[new_ind] = old_data[old_ind]
            old_ind = (old_ind + 1) % len(old_data)
        self.front = 0
        
class MidStack():
    def __init__(self):
        self.stack = ArrayStack()
        self.ad = ArrayDequeue()
        self.numOfElements = 0
    
    def __len__(self):
        return self.numOfElements 
    
    def is_empty(self):
        return self.stack.is_empty()
    
    def push(self, elem):
        self.ad.add_last(elem)
        self.numOfElements += 1
        if (self.numOfElements % 2 == 1):
            self.stack.push(self.ad.first())
            self.ad.delete_first()
        
    
    def pop(self):
        if (self.numOfElements == 0):
            raise Empty("Stack is Empty")
        elif (self.numOfElements == 1):
            self.numOfElements -= 1
            return self.stack.pop()
        self.numOfElements -= 1    
        if (self.numOfElements % 2 == 0):
            self.ad.add_first(self.stack.pop())
        return self.ad.delete_last()
    
    def top(self):
        return self.ad.last()
    
    def mid_push(self, elem):
        if (self.numOfElements % 2 == 0):
            self.stack.push(elem)
        else:
            self.ad.add_first(elem)
        self.numOfElements += 1
            
            
    

  
    
   