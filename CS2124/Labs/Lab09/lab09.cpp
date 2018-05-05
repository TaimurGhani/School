//
//  main.cpp
//  Lab09
//
//  Created by Taimur Ghani on 3/30/18.
//  Copyright © 2018 Taimur Ghani. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial { //Abstract Class
public:
    PrintedMaterial(int pages) : numberOfPages(pages) {}
    virtual void displayNumPages() const = 0;
protected:
private:
    int numberOfPages;
};

void PrintedMaterial::displayNumPages() const{
    cout << numberOfPages << endl;
}

class Magazine : public PrintedMaterial {
public:
    Magazine(int numberOfPages) : PrintedMaterial(numberOfPages) {}
    void displayNumPages() const{
        PrintedMaterial::displayNumPages();
    }
protected:
private:
};

class Book : public PrintedMaterial {
public:
    Book(int numberOfPages) : PrintedMaterial(numberOfPages) {}
    void displayNumPages() const{
        PrintedMaterial::displayNumPages();
    }
protected:
private:
};

class TextBook : public Book {
public:
    TextBook(int numberOfPages, int numIndex) : Book(numberOfPages), numOfIndexPages(numIndex) {}
    void displayNumPages() const {
        PrintedMaterial::displayNumPages();
        cout << numOfIndexPages << endl;
    }
protected:
private:
    int numOfIndexPages;
};

class Novel : public Book {
public:
    Novel(int numberOfPages) : Book(numberOfPages) {}
    void displayNumPages() const{
        PrintedMaterial::displayNumPages();
    }
protected:
private:
};

/*void displayNumberOfPages(const PrintedMaterial pm){
    pm.displayNumPages();
}*/

// tester/modeler code
int main()
{
    TextBook t(5430, 234);
    Novel n(213);
    Magazine m(6);
    
    t.displayNumPages();
    n.displayNumPages();
    m.displayNumPages();
    
    cout << "=======Task 9========" << endl;
    //PrintedMaterial pm = t; // like putting a t into a vector of PrintedMaterials
    //pm.displayNumPages();
    
    cout << "=======Task 10=======" << endl;
    PrintedMaterial* ptrM = &t;
    ptrM -> displayNumPages();
    
    cout << "=======Task 11========" << endl;
    //displayNumberOfPages(t);
    
    vector<PrintedMaterial*> vpm;
    vpm.push_back(&t);
    vpm.push_back(&n);
    vpm.push_back(&m);
    
    cout << "=======Task 15========" << endl;
    for (size_t i = 0; i < vpm.size(); i++){
        vpm[i] -> displayNumPages();
    }
    
}
