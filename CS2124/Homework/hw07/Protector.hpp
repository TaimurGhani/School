//
//  Protector.hpp
//  hw07
//
//  Created by Taimur Ghani on 4/7/18.
//  Copyright © 2018 Taimur Ghani. All rights reserved.
//

#ifndef Protector_hpp
#define Protector_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Lord;

class Protector{
public:
    Protector (const string& name, int strength);
    
    string getName() const;
    
    int getStrength() const;
    
    void setStrength(int newStrength);
    
    void setEmployed(bool boolean);
    
    bool isEmployed() const;
    
    void setBoss(Lord* protectorBoss);
    
    void runaway();
    
    virtual void makeNoise() const;
private:
    string name;
    int strength;
    bool employed;
    Lord* boss;
};

class Warrior : public Protector{
public:
    Warrior (const string& name, int strength);
    
    void makeNoise() const;
};

class Wizard : public Protector{
public:
    Wizard (const string& name, int strength);
    
    void makeNoise() const;
};

class Archer : public Warrior{
public:
    Archer (const string& name, int strength);
    
    void makeNoise() const;
};

class Swordsman : public Warrior{
public:
    Swordsman (const string& name, int strength);
    
    void makeNoise() const;
};

#endif /* Protector_hpp */
