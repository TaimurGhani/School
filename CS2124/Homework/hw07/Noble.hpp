//
//  Lord.hpp
//  hw07
//
//  Created by Taimur Ghani on 4/7/18.
//  Copyright © 2018 Taimur Ghani. All rights reserved.
//

#ifndef Noble_hpp
#define Noble_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Protector;

class Noble{
public:
    Noble(const string& name);
    string getName() const;
    
private:
    string name;
};

class PersonWithStrengthToFight : public Noble{
public:
    PersonWithStrengthToFight (const string& name, int strength);
    void battle(PersonWithStrengthToFight& opponent);
    int getStrength() const;
    void setStrength(int newStrength);
private:
    int strength;
};

class Lord : public Noble{
public:
    Lord(const string& name);
    
    void hires(Protector& protectorName);
    
    void fire(Protector& protectorName);
    
    void display() const;
    
    void battle(PersonWithStrengthToFight& person);
    
    void battle(Lord& opponent);

private:
    vector<Protector*> army;
    int strength;
};


#endif /* Noble_hpp */
