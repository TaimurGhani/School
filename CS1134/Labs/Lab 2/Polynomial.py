#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
    Polynomial.py
    Taimur Ghani
    15 September 2017
    Create a polynomial class
"""
class Polynomial:
    def __init__(self, coef = None):
        self.coef = coef
    
    def __str__(self):
        output=""
        for i in range(len(self.coef)-1, -1, -1):
            if (i == 0):
                output = output + str(self.coef[i]) 
            elif (i == len(self.coef)-1):
                output = output + str(self.coef[i]) + "x^" + str(i)+ " "  
            elif (self.coef[i] < 0):
                output = output + str(self.coef[i]) + "x^" + str(i) + " + "
            else:
                output = output + str(self.coef[i]) + "x^" + str(i) + " + "
        return output
  
      
    def eval(self, val):
      sol = 0
      self.val = val
      for i in range(len(self.coef)):
          sol += (self.coef[i]) * ((self.val) ** i)
      print(sol)
      
    def __add__(self, addPoly):
         minimum = min(self.coef(len), addPoly.coef(len))
         for i in range(minimum):
             newList = (self.coef[i] + addPoly.coef[i])
         return(newList)
         
         
 
       


poly = Polynomial([3, 7, 0, -9, 2])
poly2 = Polynomial([1, 2, 3])
print(poly + poly2)

