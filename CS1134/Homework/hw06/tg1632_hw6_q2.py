#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Oct 30 11:31:54 2017

@author: taimur
"""

class EmptyCollection(Exception):
    pass


class DoublyLinkedList:
    class Node:
        def __init__(self, data=None, next=None, prev=None):
            self.data = data
            self.next = next
            self.prev = prev

        def disconnect(self):
            self.data = None
            self.next = None
            self.prev = None


    def __init__(self):
        self.header = DoublyLinkedList.Node()
        self.trailer = DoublyLinkedList.Node()
        self.header.next = self.trailer
        self.trailer.prev = self.header
        self.size = 0

    def __len__(self):
        return self.size

    def is_empty(self):
        return (len(self) == 0)

    def first_node(self):
        if (self.is_empty()):
            raise EmptyCollection("List is empty")
        return self.header.next

    def last_node(self):
        if (self.is_empty()):
            raise EmptyCollection("List is empty")
        return self.trailer.prev

    def add_first(self, elem):
        return self.add_after(self.header, elem)

    def add_last(self, elem):
        return self.add_after(self.trailer.prev, elem)

    def add_after(self, node, elem):
        prev = node
        succ = node.next
        new_node = DoublyLinkedList.Node()
        new_node.data = elem
        new_node.prev = prev
        new_node.next = succ
        prev.next = new_node
        succ.prev = new_node
        self.size += 1
        return new_node

    def add_before(self, node, elem):
        return self.add_after(node.prev, elem)

    def delete(self, node):
        prev = node.prev
        succ = node.next
        prev.next = succ
        succ.prev = prev
        self.size -= 1
        data = node.data
        node.disconnect()
        return data

    def __iter__(self):
        if(self.is_empty()):
            return
        cursor = self.first_node()
        while(cursor is not self.trailer):
            yield cursor.data
            cursor = cursor.next

    def __str__(self):
        return '[' + '<-->'.join([str(elem) for elem in self]) + ']'

    def __repr__(self):
        return str(self)
    
class Integer:
    def __init__(self, num_str):
        self.num_str = num_str
        self.data = DoublyLinkedList()
        for i in range(len(num_str)):
            self.data.add_last(self.num_str[i])
            
    def __add__(self, other):
        dll = DoublyLinkedList()
        if len(self.data) > len(other.data):
            big = self.data
            small = other.data
        else:
            small = self.data
            big = other.data
        for i in range(len(big)):
            dll.add_last(int(big.header.next.data))
            big.header = big.header.next
        temp = dll.trailer
        
        for i in range(len(small)):
            s = temp.prev.data + int(small.trailer.prev.data)
            if (s//10 > 0):
                carry = s//10
                s = s%10
            else:
                carry = 0
            temp.prev.data = s
            temp.prev.prev.data += carry
            temp = temp.prev
            small.trailer = small.trailer.prev
        s = ""
        for i in dll:
            s += str(i)
        return Integer(s)
    
    def __str__(self):
        return "".join([str(i) for i in self.data ])
        

a = Integer("375")
b = Integer("4029")
c = a+b
print(c)
