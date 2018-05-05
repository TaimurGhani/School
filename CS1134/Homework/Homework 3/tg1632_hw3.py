#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
    tg1632_hw3.py
"""
#Question 3 
def print_triangle(n):
    if (n > 0):
        print_triangle(n-1)
        print(n * "*")

#Question 4     
def print_oppisate_triangles(n):
    if (n > 0):
        print(n * "*")
        print_oppisate_triangles(n-1)
        print(n * "*")
 
#Question 4        
def list_min(lst, low, high):
    if (low == high):
        return lst[low]
    else:
        if (lst[low] > lst[high]):
            low +=1
        else:
            high -=1
        return list_min(lst,low,high)
    
#Question 5(a)     
def count_lowercase(s, low, high):
    if (len(s) == 0):
        return 0
    if (93 <= ord(s[low]) <= 123):
        return 1 + count_lowercase(s[low+1:high+1], low, high)
    else:
        return count_lowercase(s[low+1:high+1], low, high)

#Question 5(b)
def is_number_of_lowercase_even(s, low, high):
    if (len(s) == 0):
        return None
    if (93 <= ord(s[low]) <= 123):
        return (1 + is_number_of_lowercase_even(s[low+1:high+1], low, high) % 2 == 0)
    else:
        return (is_number_of_lowercase_even(s[low+1:high+1], low, high) % 2 == 0)

#Question 6 
def appearances(s, low, high):
    if (low == high):
        return {s[low]:1}
    else:
        rest = appearances(s, low+1, high)
        if (s[low] in rest):
            rest[s[low]] += 1
        else:
            rest[s[low]] = 1
    return rest
 
#Question 7                
def flat_list(nested_lst, low, high):
    if(low == high):
        return nested_lst[low]
    if (isinstance(nested_lst[low], list)):
        return flat_list(nested_lst[low], low, high) + flat_list(nested_lst[low+1:high+1], low+1, high)
    return nested_lst[:1]+ flat_list(nested_lst[1:high], low, high)
          
    
print(flat_list([1,[2,3],[4,[5,6,[7],8]]], 0, 2))
 
