//
//  Protector.cpp
//  hw07
//
//  Created by Taimur Ghani on 4/7/18.
//  Copyright © 2018 Taimur Ghani. All rights reserved.
//

#include "Protector.hpp"
#include "Noble.hpp"

Protector::Protector (const string& name, int strength) : name(name), strength(strength), employed(false){}

string Protector::getName() const{
    return name;
}

int Protector::getStrength() const{
    return strength;
}

void Protector::setStrength(int newStrength){
    strength = newStrength;
}

void Protector::setEmployed(bool boolean){
    employed = boolean;
}

bool Protector::isEmployed() const{
    return employed;
}

void Protector::setBoss(Lord* warriorBoss){
    boss = warriorBoss;
}

void Protector::runaway(){
    cout << name << " flees in terror, abandoning his lord, " << boss->getName();
    boss -> fire(*this);
    setBoss(nullptr);
    setEmployed(false);
    
}

void Protector::makeNoise() const{
    cout <<"";
}


Warrior::Warrior (const string& name, int strength) : Protector(name, strength){}
    
void Warrior::makeNoise() const{
    cout << getName() << " Take that in the name of my lord, ";
}


Wizard::Wizard (const string& name, int strength) : Protector(name, strength){}
    
void Wizard::makeNoise() const{
    cout << "POOF! ";
}

Archer::Archer (const string& name, int strength) : Warrior(name, strength){}
    
void Archer::makeNoise() const{
    cout << "TWANG! ";
    Warrior::makeNoise();
}


Swordsman::Swordsman (const string& name, int strength) : Warrior(name, strength){}
    
void Swordsman::makeNoise() const{
    cout << "CLANG! ";
    Warrior::makeNoise();
}


