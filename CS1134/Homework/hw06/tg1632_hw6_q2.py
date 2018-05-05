#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Nov  2 17:39:16 2017

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
    def __init__(self, num_str = None):
        if (num_str == "" or num_str is None):
            self.num_str = "0"
        else:
            self.num_str = num_str
        self.data = DoublyLinkedList()
        for i in range(len(self.num_str)):
            self.data.add_last(self.num_str[i])
            
    def __add__(self, other):
        dll = DoublyLinkedList()
        self1 = Integer(self.num_str)
        other1 = Integer(other.num_str)
        if len(self1.data) > len(other1.data):
            big = self1.data
            small = other1.data
        else:
            small = self1.data
            big = other1.data
        for i in range(len(big)):
            dll.add_last((big.header.next.data))
            big.header = big.header.next
        for i in range(len(big) - len(small)):
            small.add_first(0)
        temp = dll.trailer
        #newdll = DoublyLinkedList()
        for i in range(len(small)):
            s = int(temp.prev.data) + int(small.trailer.prev.data)
            if (s//10 > 0):
                carry = s//10
                s = s%10
            else:
                carry = 0
            temp.prev.data = s
            if (temp.prev.prev.data != None):
                temp.prev.prev.data = str(int(temp.prev.prev.data) + carry)
                temp = temp.prev
                small.trailer = small.trailer.prev
            else:
                if (carry != 0):
                    temp.prev.data = int(str(carry) + str(temp.prev.data))
                else:
                    temp.prev.data = temp.prev.data + carry
        s = ""
        for i in dll:
            s += str(i)
        s = s.lstrip('0') or '0'
        return Integer(s)
    
    def __str__(self):
        return str("".join([str(i) for i in self.data ]))
    
    def __repr__(self):
        return str(self)


    def __mul__(self, other):
        dll = DoublyLinkedList()
        self1 = Integer(self.num_str)
        other1 = Integer(other.num_str)
        if len(self1.data) > len(other1.data):
                big = self1.data
                small = other1.data
        else:
                small = self1.data
                big = other1.data
        for i in range(len(big)):
                dll.add_last((big.header.next.data))
                big.header = big.header.next
        for i in range(len(big) - len(small)):
                small.add_first(0)
        print(small)
        temp=dll.trailer    
        carry = 0
        a = Integer()
        a.data.delete(a.data.first_node())
        print(a.data)
        for i in range(len(small)):
            a = Integer()
            a.data.delete(a.data.first_node())
            for j in range(i):
                a.data.add_last(0)
            s = int(temp.prev.data) * int(small.trailer.prev.data) + carry
            if (s//10 > 0):
                carry = s//10
                s = s%10
            else:
                carry = 0
            print(dll)
            temp.prev.data = s
            if (temp.prev.prev.data != None):
                temp.prev.prev.data = str(int(temp.prev.prev.data))
                temp = temp.prev
            else:
                temp.prev.data = str(temp.prev.data) + str(carry)
                
        print(dll)
        s = ""
        for i in dll:
            s += str(i)
        s = s.lstrip('0') or '0'
        return Integer(s)
            
        return(temp.data)

a = Integer("128")
b = Integer("9")
print(a*b)
