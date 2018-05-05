#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Oct 20 12:49:29 2017

@author: taimur
"""
from StackAndQueue import *

temp_file = open("maze.txt")
lines = temp_file.readlines()
temp_file.close()

maze = []
for item in lines:
    maze.append(item.split())

for row in maze:
    for item in row:
        print(item, " ", end = "")
    print()
    
class MatrixPosition():
    def __init__(self, row = 1, col = 1, direction = ""):
        self.row = row
        self.col = col
        self.direction = direction
    
    def __eq__(self, other):
        return (self.row == other.row and self.col == other.col and self.direction == other.direction)
    
    def __repr__(self):
        return "(" + str(self.row) + "," + str(self.col) + ")"

def print_path(maze_path):
    counter = 0
    print("Maze Path:")
    
    while not maze_path.is_empty():
        print(maze_path.top())
        maze_path.pop()
        counter += 1
        
    print("It took", counter, "steps to complete the maze.")