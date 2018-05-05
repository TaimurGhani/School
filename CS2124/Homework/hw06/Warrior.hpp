//
//  Warrior.hpp
//  hw06
//
//  Created by Taimur Ghani on 3/22/18.
//  Copyright © 2018 Taimur Ghani. All rights reserved.
//

#ifndef Warrior_hpp
#define Warrior_hpp

#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace WarriorCraft{
    class Noble;
    
    class Warrior{
    public:
        Warrior (const string& name, int strength);
        
        string getName() const;
        
        int getStrength() const;
        
        void setStrength(int newStrength);
        
        void setEmployed(bool boolean);
        
        bool isEmployed() const;
        
        void setBoss(WarriorCraft::Noble* warriorBoss);
        
        void runaway();
        
    private:
        string name;
        int strength;
        bool employed;
        WarriorCraft::Noble* boss;
    };
}
#endif /* Warrior_hpp */
