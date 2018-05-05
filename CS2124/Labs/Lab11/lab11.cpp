//
//  main.cpp
//  rec11
//
//  Created by Taimur Ghani on 4/13/18.
//  Copyright © 2018 Taimur Ghani. All rights reserved.
//

#include <cstdlib> // To allow NULL if no other includes
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    Node(int data = 0, Node* next = NULL) : data(data), next(next) {}
    int data;
    Node* next;
};

void listInsertHead(Node*& headPtr, int entry) {
    headPtr = new Node(entry, headPtr);
}

// Should free up your nodes, of course...
void listClear(Node*& headPtr) {
    while (headPtr) {
        Node* next = headPtr->next;
        delete headPtr;
        headPtr = next;
    }
}

void splice(Node*& insertAfter, Node* insert){
    if (insertAfter == nullptr){
        insertAfter = insert;
    }
    else{
        Node* temp = insertAfter->next;
        insertAfter->next = insert;
        while (insert->next != nullptr){
            //insertAfter->next = insert;
            //insertAfter = insertAfter->next;
            insert = insert->next;
        }
        insert->next = temp;
    }
}

bool isSubListHelper(Node* headptr, Node* checkHead){
    while (checkHead != nullptr){
        if (headptr == nullptr){
            return false;
        }
        if (headptr->data != checkHead->data){
            return false;
        }
        headptr = headptr->next;
        checkHead = checkHead->next;
    }
    return true;
}

Node* isSubList(Node* headptr, Node* checkHead){
    while (headptr != nullptr){
        if (isSubListHelper(headptr, checkHead)){
            return headptr;
        }
        else{
            headptr = headptr->next;
        }
    }
    return nullptr;
}

// This might be useful for setting up test cases. Feel free to use it
// or not as you like. Example of using would be:
// Node* myList = listBuild({1, 4, 9, 16}); // builds a list of: 1 4 9 16
Node* listBuild(const vector<int>& vals) {
    Node* result = nullptr;
    for (size_t index = vals.size(); index > 0; --index) {
        listInsertHead(result, vals[index-1]);
    }
    return result;
}

void printList(Node* head){
    if (head == nullptr){
        cout << "Failed to match";
    }
    while (head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    
}

Node* shareList(Node* first, Node* second){
    Node* temp = second;
    while (first != nullptr){
        while (second != nullptr){
            if (first == second){
                return first;
            }
            else{
                second = second->next;
            }
        }
        second = temp;
        first = first->next;
    }
    return nullptr;
}

Node* shareListSet(Node* first, Node* second){
    unordered_set<Node*> nodes;
    while (first != nullptr){
        nodes.insert(first);
        first = first->next;
    }
    while (second != nullptr){
        if (nodes.find(second) != nodes.end()){
            return second;
        }
        second = second->next;
    }
    return nullptr;
}

int main(){
    Node* lst = listBuild({5, 7, 9,  1});
    cout << "Part One:" << endl;
    cout << "L1: ";
    printList(lst);
    Node* whereTo = lst->next;
    Node* splicer = listBuild({6, 3, 2});
    cout << "L2: ";
    printList(splicer);
    cout << "Target: ";
    printList(whereTo);
    splice(whereTo, splicer);
    cout << "L1: ";
    printList(lst);
    cout << "L2: ";
    printList(splicer);
    cout << "========================" << endl << endl;
    
    Node* lst2 = listBuild({1, 2, 3, 2, 3, 2, 4, 5, 6});
    cout << "Part Two:" << endl;
    cout << "Target: ";
    printList(lst2);
    
    
    Node* sub = listBuild({2, 3});
    cout << "Attempted Match: ";
    printList(sub);
    printList(isSubList(lst2, sub));
    cout << endl;
    
    Node* sub2 = listBuild({7});
    cout << "Attempted Match: ";
    printList(sub2);
    printList(isSubList(lst2, sub2));
    cout << endl;
    cout << "========================" << endl << endl;
    
    Node* lst3 = listBuild({1, 2, 3, 2, 3, 2, 4, 5, 6});
    cout << "Target: ";
    printList(lst3);
    Node* lst4 = lst3->next->next;
    cout << "Attempted Match: ";
    printList(lst4);
    printList(shareList(lst3, lst4));
    printList(shareListSet(lst3, lst4));
    
    
    
}

