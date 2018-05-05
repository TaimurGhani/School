//
//  Warrior.cpp
//  hw06
//
//  Created by Taimur Ghani on 3/22/18.
//  Copyright © 2018 Taimur Ghani. All rights reserved.
//
#include <string>
#include "Warrior.hpp"
#include "Noble.hpp"

namespace WarriorCraft {
    Warrior::Warrior (const string& name, int strength) : name(name), strength(strength), employed(false){}
    
    string Warrior::getName() const{
        return name;
    }
    
    int Warrior::getStrength() const{
        return strength;
    }
    
    void Warrior::setStrength(int newStrength){
        strength = newStrength;
    }
    
    void Warrior::setEmployed(bool boolean){
        employed = boolean;
    }
    
    bool Warrior::isEmployed() const{
        return employed;
    }
    
    void Warrior::setBoss(Noble* warriorBoss){
        boss = warriorBoss;
    }
    
    void Warrior::runaway(){
        cout << name << " flees in terror, abandoning his lord, " << boss->getName();
        boss -> fire(*this);
        setBoss(nullptr);
        setEmployed(false);
        
    }
}

