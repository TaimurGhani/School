//
//  polynomial.cpp
//  hw09
//
//  Created by Taimur Ghani on 5/1/18.
//  Copyright © 2018 Taimur Ghani. All rights reserved.
//

#include "polynomial.hpp"
Node::Node(int data, Node* next, Node* prev) : data(data), next(next), prev(prev){}

ostream& operator<<(ostream& os, const Polynomial& poly){
    Node* p = poly.trailer -> prev;
    int exponent = poly.theSize-1;
    if (poly.theSize == 0){
        os << "0";
    }
    while (p!= poly.header) {
        if (p->data != 0){
            if (exponent == 0) os << p->data;
            else{
                if (p->data != 1){
                    os << p->data;
                }
                os << "x";
                if (exponent == 1) os << " + ";
                else os << "^" << exponent << " + ";
            }
        }
        p = p->prev;
        --exponent;
    }
    return os;
}
    
bool operator==(const Polynomial& lhs, const Polynomial& rhs){
    if (lhs.theSize != rhs.theSize){
        return false;
    }
    else{
        Node* lhsInd = lhs.header->next;
        Node* rhsInd = rhs.header->next;
        while (lhsInd != lhs.trailer){
            if (lhsInd->data != rhsInd->data) return false;
            lhsInd = lhsInd->next;
            rhsInd = rhsInd->next;
        }
    }
    return true;
}
    
Polynomial::Polynomial() : theSize(0), header(new Node()), trailer(new Node()){
    header->next = trailer;
    trailer->prev = header;
}

Polynomial::Polynomial(const vector<int>& v) : theSize(0), header(new Node()), trailer(new Node()){
    header->next = trailer;
    trailer->prev = header;
    for (int constant : v){
        push_front(constant);
    }
}

Polynomial::Polynomial(const Polynomial& rhs){
        theSize = 0;
        header=new Node();
        trailer=new Node();
        header->next = trailer;
        trailer->prev = header;
        Node* curr = rhs.header->next;
        for (size_t index = 0; index < rhs.theSize; ++index) {
            push_back(curr->data);
            curr = curr->next;
        }
    }
    
Polynomial::~Polynomial(){
    Node* curr = trailer->prev;
    while (curr != header){
        curr=curr->prev;
        curr->next->next=new Node();
        curr->next->prev=new Node();
        delete curr;
        --theSize;
    }
}
    
Polynomial& Polynomial::operator=(const Polynomial& rhs){
    if (this != &rhs) {
        // free up
        Node* curr = trailer->prev;
        while (curr != header){
            curr=curr->prev;
            curr->next->next=new Node();
            curr->next->prev=new Node();
            delete curr;
            --theSize;
        }
        // Allocate and copy
        header=new Node();
        trailer=new Node();
        header->next = trailer;
        trailer->prev = header;
        curr = rhs.header->next;
        for (size_t index = 0; index < rhs.theSize; ++index) {
            push_back(curr->data);
            curr = curr->next;
        }
    }
    return *this;
}
    
Polynomial& Polynomial::operator+=(const Polynomial& rhs){
    if (theSize < rhs.theSize){
        Node* curr = header->next;
        Node* index = rhs.header->next;
        while(curr != trailer){
            curr->data += index->data;
            curr = curr->next;
            index = index->next;
        }
        while (index != rhs.trailer){
            push_back(index->data);
            index = index->next;
        }
    }
    else{
        Node* curr = header->next;
        Node* index = rhs.header->next;
        while(index != rhs.trailer){
            curr->data += index->data;
            curr = curr->next;
            index = index->next;
        }
    }
    return *this;
}


void Polynomial::push_front(int data){
    Node* newNode = new Node(data, header->next, header);
    header->next->prev = newNode;
    header->next = newNode;
    ++theSize;
}

void Polynomial::push_back(int data){
    if (theSize == 0){
        Node* newNode = new Node(data);
        newNode->next = trailer;
        newNode->prev = header;
        trailer->prev = newNode;
        header->next = newNode;
    }
    else{
        Node* newNode = new Node(data, trailer, trailer->prev);
        trailer->prev->next = newNode;
        trailer->prev = newNode;
    }
    ++theSize;
}

int Polynomial::evaluate(int x) const{
    int result = 0;
    Node* curr = trailer->prev;
    int exponent = theSize-1;
    while (curr != header){
        int term = curr->data;
        for (int i = 0; i < exponent; ++i){
            term *= x;
        }
        result += term;
        --exponent;
        curr = curr->prev;
    }
    return result;
}

Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs) {
    Polynomial temp = lhs;
    return temp += rhs;
}

bool operator!=(const Polynomial& lhs, const Polynomial& rhs) {
    return !(lhs == rhs);
}
