#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
    tg1632_hw4.py
    Taimur Ghani
    13 October 2017
    Homework 4
"""

#Problem 1
def split_by_sign(lst, low, high):
    if (low > high):
        return lst
    if (lst[high] < 0):
        lst.insert(low, lst[high])
        lst.pop(high+1)
    return split_by_sign(lst, low+1, high)

#Problem 2
def permutations(lst, low, high):
    if (len(lst) == 1):
        return [lst]
    else:
        rl = []
        lst = lst[low:high+1]
        for i in range(len(lst)):
            start = lst[i]
            rest = lst[:i] + lst[i+1:]
            for item in (permutations(rest, low, high)):
                rl.append([start]+item)
    return rl

#Problem 3
import ctypes  # provides low-level arrays
def make_array(n):
    return (n * ctypes.py_object)()

class MyList:
    def __init__(self):
        self.data = make_array(1)
        self.capacity = 1
        self.n = 0


    def __len__(self):
        return self.n


    def append(self, val):
        if (self.n == self.capacity):
            self.resize(2 * self.capacity)
        self.data[self.n] = val
        self.n += 1


    def resize(self, new_size):
        new_array = make_array(new_size)
        for i in range(self.n):
            new_array[i] = self.data[i]
        self.data = new_array
        self.capacity = new_size


    def extend(self, other):
        for elem in other:
            self.append(elem)


    def __getitem__(self, ind):
        if (not (0 <= ind <= self.n - 1)):
            raise IndexError('invalid index')

        return self.data[ind]


    def __setitem__(self, ind, val):
        if (not (0 <= ind <= self.n - 1)):
            raise IndexError('invalid index')
        self.data[ind] = val
    
    def __str__(self):
        output = "["
        for i in range(len(self)):
            if (self[i] != None):
                output += str(self[i]) + ", "
        output = output[:len(output)-2]
        output += "]"
        return output
        
    def __repr__(self):
        return self.__str__() 
        
    def insert(self, index, val):
        if (not (0 <= index <= self.n)):
            raise IndexError("invalid index")
        if (self.n == self.capacity):
            self.resize(2 * self.capacity)
        if (index == self.n):
            self.append(val)
        else:
            for i in range(index, self.n):
                self.append(self[i])
                self[index] = val
        
    def pop(self):
        empty = []
        if (self.n == 0):
            raise IndexError("Empty List")
        output = self[len(self)-1]
        for i in range (0, len(self)-1):
            empty.append(self[i])
        self[len(self)-1] = None  
        #self.resize(len(self)-1)
        return output

#Problem 4            
def find_duplicates(lst):
    dup = []
    for i in range (len(lst)-1):
        x = abs(lst[i])
        if (lst[x] > 0):
            lst[x] = -lst[x]
        else:
            dup.append(-1*lst[x])
    return dup

#Problem 5
def remove_all(lst, value):
    x = len(lst)
    for i in range(len(lst)):
        if (lst[i] != value):
            lst.append(lst[i])
    lst[:] = lst[x:]
      

            
    
         
    

        
    