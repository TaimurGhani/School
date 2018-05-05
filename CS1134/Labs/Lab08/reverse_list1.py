#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Oct 27 12:09:03 2017

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
    
def reverse_list1(lst):
    low = 0
    high = len(lst)-1
    temp1 = lst.header.next
    temp2 = lst.trailer.prev
    while (low < high):
        temp1.data, temp2.data = temp2.data, temp1.data
        temp1 = temp1.next
        temp2=temp2.prev
        low += 1
        high -= 1
    return lst

def reverse_list2(lst):
    head = lst.header.next
    tail = lst.trailer.prev
    tail.prev, tail.next = DoublyLinkedList.Node(), tail.prev
    head.next, head.prev = DoublyLinkedList.Node(), head.next
    low = 1
    high = (len(lst)-1)-1
    head = head.next
    tail = tail.prev
    while(low < high):
        head, tail = tail, head
        tail.prev, tail.next = tail.next, tail.prev
        head.next, head.prev = head.prev, head.next
        low += 1
        high -= 1
    t = lst.header.next
    for i in range(len(lst)):
        print(t.data)
        t = t.prev
        
    return (lst)
    

a = DoublyLinkedList()
a.add_last(1)
a.add_last(2)
a.add_last(3)
a.add_last(4)
a.add_last(5)
a.add_last(6)
a.add_last(7)
a.add_last(8)
a.add_last(9)
print(a)
print(reverse_list2(a))
        
