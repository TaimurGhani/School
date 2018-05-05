#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Oct 20 12:03:17 2017

@author: taimur
"""

class deque:
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
        self.front -= 1
        self.data[self.front] = elem
        
        
    def add_last(self, elem):
        if (self.numOfElems == len(self.data)):
            self.resize(2*len(self.data))
        self.data[(self.front+self.numOfElems)%len(self.data)] = elem
        self.numOfElems += 1
        
    def delete_first(self):
        self.data[self.front] = None
        self.front += 1
        self.numOfElems -= 1
        if (self.numOfElems < len(self.data) // 4):
            self.resize(len(self.data) // 2)
        
        
    def delete_last(self):
        self.data[(self.front+self.numOfElems-1)%(len(self.data))] = None
        self.numOfElems -= 1
        
    def resize(self, new_cap):
        old_data = self.data
        self.data = [None] * new_cap
        old_ind = self.front
        for new_ind in range(self.numOfElems):
            self.data[new_ind] = old_data[old_ind]
            old_ind = (old_ind + 1) % len(old_data)
        self.front = 0
   


