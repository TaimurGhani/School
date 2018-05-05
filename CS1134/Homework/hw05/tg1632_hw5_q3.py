#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Oct 27 00:13:15 2017

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
    
    def first(self):
        return self.data[0]
        
scan = input("-->")   
operators = "+-*/"
stack=ArrayStack()
dic = {}
#gets user input until "done()"
while (scan != "done()"):
    stack=ArrayStack()
    
    #creates a list of all the characters excluding spaces
    lst = scan.split(" ")
    if len(lst)>1:
        if (lst[1] == "="):
            dic[lst[0]] = None
            lst2 = lst[2:]
        else:
            lst2 = lst
            
        #goes through the elemts that will be getting operations performed on them
        for c in lst2:
            if c in operators:
                
                #pops off the last two numbers
                a = stack.pop()
                b = stack.pop()
                
                #checks to see if they are variables; makes them the val from key
                if (a in dic):
                    a = dic[a]
                if (b in dic):
                    b = dic[b]
                    
                #performs operations
                if (c == "+"):
                    stack.push(a + b)
                elif (c == "-"):
                    stack.push(-1 * a + b)
                elif (c == "*"):
                    stack.push(a * b)
                elif (c == "/"):
                    stack.push(1/a * b)
                #if  is a already in a dictionary (means equal sign is there) add to stack
                elif c in dic:
                    stack.push(c)
                
            #push everything else to a stack
            elif (c.isdigit()):
                stack.push(int(c))
            else:
                stack.push(c)
    else:
        stack.push(lst[0])
    if len(lst) == 1:
        if (stack.top().isdigit()):
            print(int(stack.pop()))
        else:
            print(dic[stack.pop()])
    elif (any(c.isalpha() for c in scan)):
        if (lst[1] == "="):
            dic[lst[0]] = stack.pop()
            print(lst[0])
        else: 
            print(stack.pop())
    else:
        print(stack.pop())
    scan = input("-->") 
        
    