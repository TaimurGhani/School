// Doubly linked list
//  Test code

#include <cstdlib>
#include <iostream>
using namespace std;

struct Node{
    Node(int data = 0, Node* next = nullptr, Node* prev = nullptr) : data(data) {}
    int data;
    Node* next;
    Node* prev;
};


class List {
    friend ostream& operator<< (ostream& os, List& lst){
        Node* curr = lst.header->next;
        os << "[";
        while (curr != lst.trailer){
            os << curr->data << ", ";
            curr = curr->next;
        }
        os << "]";
        return os;
    }
public:
     class Iterator{
         friend class List;
        friend bool operator!=(const Iterator& lhs, const Iterator& rhs) {
            return (lhs.node != rhs.node);
        }
        friend bool operator==(const Iterator& lhs, const Iterator& rhs) {
            return !(operator!=(lhs, rhs));
        }
    public:
        Iterator(Node* node) : node(node) {}
        Iterator& operator++() {
            node = node->next;
            return *this;
        }
        Iterator& operator--() {
            node = node->prev;
            return *this;
        }
        int operator*() const{
            return node->data;
        }
        
        int& operator*() {
            return node->data;
        }
        
        Node* getNode(){
            return node;
        }

    private:
        Node* node;
    };
    
   
    
    
    List() : header(new Node()), trailer(new Node()), theSize(0) {
        trailer->prev = header;
        header->next = trailer;
    }
    
    List(const List& rhs){
        header=new Node();
        trailer=new Node();
        Node* curr = rhs.header->next;
        for (size_t index = 0; index < rhs.theSize; ++index) {
            push_back(curr->data);
            curr = curr->next;
        }
        
    }

    ~List(){
        Node* curr = trailer->prev;
        while (curr != header){
            curr=curr->prev;
            curr->next->next=nullptr;
            curr->next->prev=nullptr;
            delete curr;
            --theSize;
        }
    }

    List& operator=(const List& rhs){
        if (this != &rhs) {
            // free up
            Node* curr = trailer->prev;
            while (curr != header){
                curr=curr->prev;
                curr->next->next=nullptr;
                curr->next->prev=nullptr;
                delete curr;
                --theSize;
            }
            //delete data;

            // Allocate and copy
            header=new Node();
            trailer=new Node();
            curr = rhs.header->next;
            for (size_t index = 0; index < rhs.theSize; ++index) {
                push_back(curr->data);
                curr = curr->next;
            }
        }
        return *this;
    }
    
    int operator[](int i) const{
        int loop = i;
        Node* curr = header->next;
        while (loop){
            curr = curr->next;
            --loop;
        }
        return curr->data;
    }
    
    int& operator [](int i) {
        int loop = i;
        Node* curr = header->next;
        while (loop){
            curr = curr->next;
            --loop;
        }
        return curr->data;;
    
    }
    
    void push_back(int data) {
        if (theSize == 0){
            Node* newNode = new Node(data);
            newNode->next = trailer;
            newNode->prev = header;
            trailer->prev = newNode;
            header->next = newNode;
        }
        else{
            Node* newNode = new Node(data);
            newNode->next = trailer;
            newNode->prev = trailer->prev;
            trailer->prev->next = newNode;
            trailer->prev = newNode;
        }
        ++theSize;
    }
    
    int front() {
        if (theSize == 0){
            return -1;
        }
        return header->next->data;
    }
    
    void push_front(int data){
        if (theSize == 0){
            push_back(data);
        }
        else{
            Node* newNode = new Node(data);
            newNode->next = header->next;
            newNode->prev = header;
            header->next->prev = newNode;
            header->next = newNode;
            ++theSize;
        }
        
    }
    
    void pop_front(){
        if (theSize == 1){
            pop_back();
        }
        else{
            Node* temp = header->next->next;
            header->next->next = nullptr;
            header->next->prev = nullptr;
            delete header->next;
            header->next = temp;
            temp->prev = header;
            --theSize;
        }

    }
    
    int back() {
        return trailer->prev->data;
    }
    
    int size(){
        return theSize;
    }
    
    void pop_back(){
        Node* temp = trailer->prev->prev;
        trailer->prev->next = nullptr;
        trailer->prev->prev = nullptr;
        delete trailer->prev;
        temp->next = trailer;
        trailer->prev = temp;
        --theSize;
    }
    
    void clear(){
        while (size()) {
            pop_back();
        }
    }
    
    Iterator begin() {
        return header->next;
    }
    
    const Iterator begin() const{
        return header->next;
    }
    
    Iterator end() {
        return trailer;
    }
    
    const Iterator end() const{
        return trailer;
    }

    Iterator insert(Iterator iter, int data){
        Node* newNode = new Node(data);
        newNode->next = iter.node;
        newNode->prev = iter.node->prev;
        iter.node->prev->next=newNode;
        iter.node->prev=newNode;
        ++theSize;
        return Iterator(newNode);
    }
    
    Iterator erase(Iterator iter){
        Node* tempNext = iter.node->next;
        Node* tempPrev = iter.node->prev;
        iter.getNode()->next = nullptr;
        iter.getNode()->prev = nullptr;
        delete iter.node;
        tempNext->prev = tempPrev;
        tempPrev->next =tempNext;
        --theSize;
        return --iter;
    }
    
private:
    Node* header;
    Node* trailer;
    int theSize;


    
};

void printListInfo(List& myList) {
    cout << "size: " << myList.size()
    << ", front: " << myList.front()
    << ", back(): " << myList.back()
    << ", list: " << myList << endl;
}

// Task 8
void doNothing(List aList) {
    cout << "In doNothing\n";
    printListInfo(aList);
    cout << endl;
    cout << "Leaving doNothing\n";
}

int main() {
    
    // Task 1
    cout << "\n------Task One------\n";
    List myList;
    printListInfo(myList);
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList.push_back(" << i*i << ");\n";
        myList.push_back(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_back\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_back();
    }
    cout << "===================\n";

    // Task2
    cout << "\n------Task Two------\n";
    cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList2.push_front(" << i*i << ");\n";
        myList.push_front(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_front\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_front();
    }
    cout << "===================\n";

    // Task3
    cout << "\n------Task Three------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        myList.push_back(i*i);
    }
    printListInfo(myList);
    cout << "Now clear\n";
    myList.clear();
    cout << "Size: " << myList.size() << ", list: " << myList << endl;
    cout << "===================\n";

    // Task4
    cout << "\n------Task Four------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    cout << "Display elements with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Add one to each element with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) myList[i] += 1;
    cout << "And print it out again with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;

    // Task 5
    cout << "\n------Task Five------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    printListInfo(myList);
    cout << "Now display the elements in a ranged for\n";
    for (int x : myList) cout << x << ' ';
    cout << endl;
    cout << "And again using the iterator type directly:\n";
    for (List::Iterator iter = myList.begin(); iter != myList.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
    cout << "WOW!!! (I thought it was cool.)\n";

    // Task 6
    cout << "\n------Task Six------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Filling an empty list with insert at begin(): "
    << "i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i*i);
    printListInfo(myList);
    // ***Need test for insert other than begin/end***
    cout << "===================\n";

    // Task 7
    cout << "\n------Task Seven------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    cout << "Erasing the elements in the list, starting from the beginning\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.erase(myList.begin());
    }
    printListInfo(myList);
    // ***Need test for erase other than begin/end***
    cout << "===================\n";

    // Task 8
    cout << "\n------Task Eight------\n";
    cout << "Copy control\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Calling doNothing(myList)\n";
    doNothing(myList);
    cout << "Back from doNothing(myList)\n";
    printListInfo(myList);

    cout << "Filling listTwo with insert at begin: i*i for i from 0 to 9\n";
    List listTwo;
    for (int i = 0; i < 10; ++i) listTwo.insert(listTwo.begin(), i*i);
    printListInfo(listTwo);
    cout << "listTwo = myList\n";
    listTwo = myList;
    cout << "myList: ";
    printListInfo(myList);
    cout << "listTwo: ";
    printListInfo(listTwo);
    cout << "===================\n";
}

