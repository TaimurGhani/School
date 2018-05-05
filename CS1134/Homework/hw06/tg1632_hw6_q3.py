#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Nov  2 19:25:08 2017

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

class Empty(Exception):
    pass

class CompactString:
    def __init__(self, orig_str):
        self.data = DoublyLinkedList()
        self.orig_str = orig_str
        counter=1
        for i in range(len(self.orig_str)-1):
            if (orig_str[i] == orig_str[i + 1]):
                counter += 1
            else:
                self.data.add_last((orig_str[i], counter))
                counter = 1
        if len(orig_str)>0:
            self.data.add_last(((orig_str[len((orig_str))-1]), counter))
        
    def __add__(self, other):
        cs = DoublyLinkedList()
        self1 = self
        other1 = other
        if (len(self1.orig_str) > 0 and len(other1.orig_str)>0):        
            if (self1.data.last_node().data[0] == other1.data.first_node().data[0]):
                count = self1.data.last_node().data[1] + other1.data.first_node().data[1]
                letter = self1.data.last_node().data[0]
                self1.data.delete(self1.data.last_node())
                other1.data.delete(other1.data.first_node())
                self1.data.add_last((letter,count))
            temp = self1.data.header.next
            for i in range(len(self1.data)):
                cs.add_last(temp.data)
                temp = temp.next
            temp = other1.data.header.next
            for i in range(len(other1.data)):
                cs.add_last(temp.data)
                temp = temp.next
            s = ""
            for item in cs:
                for j in range(item[1]):
                    s += item[0]
            return CompactString(s)
        else:
            if (len(self1.orig_str) == 0):
                return other1
            else:
                return self1
            
        
    def __lt__(self, other):
        self1 = CompactString(self.orig_str)
        other1 = CompactString(other.orig_str)
        while (not self1.data.is_empty() and not other1.data.is_empty()):
            if (self1.data.header.next.data[0] == other1.data.header.next.data[0]):
                if (self1.data.header.next.data[1] == other1.data.header.next.data[1]):
                    self1.data.delete(self1.data.first_node())
                    other1.data.delete(other1.data.first_node())
                elif (self1.data.header.next.data[1] > other1.data.header.next.data[1]):
                    tup = (self1.data.header.next.data[0],self1.data.header.next.data[1] - other1.data.header.next.data[1])
                    self1.data.header.next.data = tup
                    other1.data.delete(other1.data.header.next)
                elif (self1.data.header.next.data[1] < other1.data.header.next.data[1]):
                    tup = (self1.data.header.next.data[0],other1.data.header.next.data[1] - self1.data.header.next.data[1])
                    other1.data.header.next.data = tup
                    self1.data.delete(self1.data.header.next)
            else:
                if (self1.data.header.next.data[0] < other1.data.header.next.data[0]):
                    return True
                else:
                    return False
        if (not self1.data.is_empty() and other1.data.is_empty()):
            return False
        if (self1.data.is_empty() and not other1.data.is_empty()):
            return True
        if (self1.data.is_empty() and other1.data.is_empty()):
            return False
    
    def __le__(self, other):
        self1 = CompactString(self.orig_str)
        other1 = CompactString(other.orig_str)
        while (not self1.data.is_empty() and not other1.data.is_empty()):
            if (self1.data.header.next.data[0] == other1.data.header.next.data[0]):
                if (self1.data.header.next.data[1] == other1.data.header.next.data[1]):
                    self1.data.delete(self1.data.first_node())
                    other1.data.delete(other1.data.first_node())
                elif (self1.data.header.next.data[1] > other1.data.header.next.data[1]):
                    tup = (self1.data.header.next.data[0],self1.data.header.next.data[1] - other1.data.header.next.data[1])
                    self1.data.header.next.data = tup
                    other1.data.delete(other1.data.header.next)
                elif (self1.data.header.next.data[1] < other1.data.header.next.data[1]):
                    tup = (self1.data.header.next.data[0],other1.data.header.next.data[1] - self1.data.header.next.data[1])
                    other1.data.header.next.data = tup
                    self1.data.delete(self1.data.header.next)
            else:
                if (self1.data.header.next.data[0] < other1.data.header.next.data[0]):
                    return True
                else:
                    return False
        if (not self1.data.is_empty() and other1.data.is_empty()):
            return False
        if (self1.data.is_empty() and not other1.data.is_empty()):
            return True
        if (self1.data.is_empty() and other1.data.is_empty()):
            return True
    
    def __gt__(self, other):
        self1 = CompactString(self.orig_str)
        other1 = CompactString(other.orig_str)
        while (not self1.data.is_empty() and not other1.data.is_empty()):
            if (self1.data.header.next.data[0] == other1.data.header.next.data[0]):
                if (self1.data.header.next.data[1] == other1.data.header.next.data[1]):
                    self1.data.delete(self1.data.first_node())
                    other1.data.delete(other1.data.first_node())
                elif (self1.data.header.next.data[1] > other1.data.header.next.data[1]):
                    tup = (self1.data.header.next.data[0],self1.data.header.next.data[1] - other1.data.header.next.data[1])
                    self1.data.header.next.data = tup
                    other1.data.delete(other1.data.header.next)
                elif (self1.data.header.next.data[1] < other1.data.header.next.data[1]):
                    tup = (self1.data.header.next.data[0],other1.data.header.next.data[1] - self1.data.header.next.data[1])
                    other1.data.header.next.data = tup
                    self1.data.delete(self1.data.header.next)
            else:
                if (self1.data.header.next.data[0] > other1.data.header.next.data[0]):
                    return True
                else:
                    return False
        if (not self1.data.is_empty() and other1.data.is_empty()):
            return True
        if (self1.data.is_empty() and not other1.data.is_empty()):
            return False
        if (self1.data.is_empty() and other1.data.is_empty()):
            return False
        
    def __ge__(self, other):
        self1 = CompactString(self.orig_str)
        other1 = CompactString(other.orig_str)
        while (not self1.data.is_empty() and not other1.data.is_empty()):
            if (self1.data.header.next.data[0] == other1.data.header.next.data[0]):
                if (self1.data.header.next.data[1] == other1.data.header.next.data[1]):
                    self1.data.delete(self1.data.first_node())
                    other1.data.delete(other1.data.first_node())
                elif (self1.data.header.next.data[1] > other1.data.header.next.data[1]):
                    tup = (self1.data.header.next.data[0],self1.data.header.next.data[1] - other1.data.header.next.data[1])
                    self1.data.header.next.data = tup
                    other1.data.delete(other1.data.header.next)
                elif (self1.data.header.next.data[1] < other1.data.header.next.data[1]):
                    tup = (self1.data.header.next.data[0],other1.data.header.next.data[1] - self1.data.header.next.data[1])
                    other1.data.header.next.data = tup
                    self1.data.delete(self1.data.header.next)
            else:
                if (self1.data.header.next.data[0] > other1.data.header.next.data[0]):
                    return True
                else:
                    return False
        if (not self1.data.is_empty() and other1.data.is_empty()):
            return True
        if (self1.data.is_empty() and not other1.data.is_empty()):
            return False
        if (self1.data.is_empty() and other1.data.is_empty()):
            return True
        
    def __str__(self):
        s=""
        for item in self.data:
            for j in range(item[1]):
                s += item[0]
        return s

    def __repr__(self):
        return str(self)

         
    