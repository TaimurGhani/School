//
//  polynomial.hpp
//  hw09
//
//  Created by Taimur Ghani on 5/1/18.
//  Copyright © 2018 Taimur Ghani. All rights reserved.
//

#ifndef polynomial_hpp
#define polynomial_hpp

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;

struct Node {
    Node(int data = -1, Node* next = nullptr, Node* prev = nullptr);
    int data;
    Node* next;
    Node* prev;
};

class Polynomial{
    friend ostream& operator<<(ostream& os, const Polynomial& poly);
    friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);
public:
    Polynomial();
    Polynomial(const vector<int>& v);
    Polynomial(const Polynomial& rhs);
    ~Polynomial();
    Polynomial& operator=(const Polynomial& rhs);
    Polynomial& operator+=(const Polynomial& rhs);
    void push_front(int data);
    void push_back(int data);
    int evaluate(int x) const;
private:
    int theSize;
    Node* header;
    Node* trailer;
};

Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);
bool operator!=(const Polynomial& lhs, const Polynomial& rhs);

#endif /* polynomial_hpp */
