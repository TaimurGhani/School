//
//  main.cpp
//  Lab14
//
//  Created by Taimur Ghani on 5/4/18.
//  Copyright © 2018 Taimur Ghani. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;


//Task 1
bool evenNumBits(int n){
    if (n == 0){
        return true;
    }
    else if (n == 1){
        return false;
    }
    if (n % 2 == 1){
        return (!evenNumBits(n/2));
    }
    return evenNumBits(n/2);
}

//Task 2
struct Node{
    Node (int data = 0, Node* next = nullptr) : data(data), next(next){}
    int data;
    Node* next;
};

Node* recurSum(Node* one, Node* two){
    if (one != nullptr && two != nullptr){
        return new Node(one->data + two->data, recurSum(one->next, two->next));
    }
    else if (one != nullptr && two == nullptr){
        return new Node(one->data, recurSum(one->next, two));
    }
    else if (one == nullptr && two != nullptr){
        return new Node(two->data, recurSum(one, two->next));
    }
    return nullptr;
}

//Task 3
struct TNode {
    TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
    int data;
    TNode *left, *right;
};

int maxTree(TNode* root) {
    if (root == nullptr){
        throw invalid_argument("Invalid Tree");
    }
    else if (root->left != nullptr && root->right == nullptr){
        return max(root->data, maxTree(root->left));
    }
    else if (root->left == nullptr && root->right != nullptr){
        return max(root->data, maxTree(root->right));
    }
    else if (root->left != nullptr && root->right != nullptr){
        return max(root->data, max(maxTree(root->left), maxTree(root->right)));
    }
    return root->data;
}

//Task 4
bool palindrome(char* c, int len){
    if (len < 2){
        return true;
    }
    if (c[0] == c[len-1]){
        return palindrome((c+1), len-2);
    }
    return false;
}

//Task 5
int towers(int n, char start, char target, char spare) {
    if (n==0) return 0;
    return 1 + towers(n-1, start, spare, target) + towers(n-1, spare, target, start);

}

//Task 6
void mystery(int n) {
    if (n > 1) {
        cout << 'a';
        mystery(n/2);
        cout << 'b';
        mystery(n/2);
    }
    cout << 'c';
}

int main(int argc, const char * argv[]) {
    //Task 1
    cout << "Task 1:" << endl;
    cout << evenNumBits(62) << endl;
    cout << evenNumBits(10) << endl;
    cout << endl;
    
    //Task 2
    cout << "Task 2:" << endl;
    Node* head = new Node();
    head->next = new Node(1);
    head->next->next = new Node(2);
    Node* head2 = new Node();
    head2->next = new Node(3);
    head2->next->next = new Node(4);
    
    Node* newHead = recurSum(head, head2);
    Node* curr = newHead->next;
    while (curr != nullptr){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl << endl;
    
    //Task 3
    cout << "Task 3:" << endl;
    TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
    try{
        cout << maxTree(&f) << endl;
    }
    catch (exception &e){
        cerr << e.what() << endl;
    }
    
    try{
        cout << maxTree(nullptr) << endl;
    }
    catch (exception &e){
        cerr << e.what() << endl;
    }
    
    cout << endl;
    
    
    //Task 4
    cout << "Task 4:" << endl;
    char s[] = "racecar";
    if (palindrome(s, 7)) { cout << "Yes!\n"; }
    else { cout << "No!\n"; }
    
    char tg[] = "TaimurGhani";
    if (palindrome(tg, 11)) { cout << "Yes!\n"; }
    else { cout << "No!\n"; }
    cout << endl;
    
    //Task 5
    cout << "Task 5:" << endl;
    for (int i = 1; i <= 10; ++i){
      cout << towers(i, 'a', 'b', 'c') << endl;
    }
    cout << endl;
    
    //Task 6
    cout << "Task 6:" << endl;
    for (int i = 0; i <= 10; ++i){
        cout << "n = " << i << ": ";
        mystery(i);
        cout << endl;
    }
    cout << endl;
    
    
    
}
