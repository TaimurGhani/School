#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Oct 27 18:35:31 2017

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
    
    
class ArrayQueue:
    INITIAL_CAPACITY = 10

    def __init__(self):
        self.data = [None] * ArrayQueue.INITIAL_CAPACITY
        self.num_of_elems = 0
        self.front_ind = 0

    def __len__(self):
        return self.num_of_elems

    def is_empty(self):
        return (self.num_of_elems == 0)

    def enqueue(self, elem):
        if (self.num_of_elems == len(self.data)):
            self.resize(2 * len(self.data))
        back_ind = (self.front_ind + self.num_of_elems) % len(self.data)
        self.data[back_ind] = elem
        self.num_of_elems += 1

    def dequeue(self):
        if (self.is_empty()):
            raise Empty("Queue is empty")
        value = self.data[self.front_ind]
        self.data[self.front_ind] = None
        self.front_ind = (self.front_ind + 1) % len(self.data)
        self.num_of_elems -= 1
        if(self.num_of_elems < len(self.data) // 4):
            self.resize(len(self.data) // 2)
        return value

    def first(self):
        if self.is_empty():
            raise Empty("Queue is empty")
        return self.data[self.front_ind]

    def resize(self, new_cap):
        old_data = self.data
        self.data = [None] * new_cap
        old_ind = self.front_ind
        for new_ind in range(self.num_of_elems):
            self.data[new_ind] = old_data[old_ind]
            old_ind = (old_ind + 1) % len(old_data)
        self.front_ind = 0
        
def permutations(lst):
    perms = []
    stack = ArrayStack()
    que = ArrayQueue()
    for i in range(len(lst)):
        stack.push(lst[i])
    while (len(stack) > 0):
        start = stack.pop()
        if (len(que) == 0):
            que.enqueue([start])
        else:
            #take two elements and find perms, then add another, etc
            for i in range(len(que)):
                permutation = que.dequeue()
                #add start to each position in the each already made 'perm'
                for j in range(len(permutation)+1):
                    part1=permutation[0:j]
                    part2=permutation[j:]
                    que.enqueue(part1 + [start] + part2)
                print(que.data)
    print(que.data)
    while (len(que) > 0):
        perms.append(que.dequeue())
    return perms





