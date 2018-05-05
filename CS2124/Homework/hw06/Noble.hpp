//
//  Noble.hpp
//  hw06
//
//  Created by Taimur Ghani on 3/22/18.
//  Copyright © 2018 Taimur Ghani. All rights reserved.
//

#ifndef Noble_hpp
#define Noble_hpp

#include <vector>
#include <iostream>
#include <string>

using namespace std;
namespace WarriorCraft{
    
    class Warrior;
    
    class Noble{
        friend ostream& operator<<(ostream& os, Noble& noble);
    public:
        Noble (const string& name);
        
        void hire(WarriorCraft::Warrior& warriorName);
        
        void fire(WarriorCraft::Warrior& warriorName);
        
        void display() const;
        
        string getName() const;
        
        void battle(Noble& opponent);
        
    private:
        string name;
        vector<WarriorCraft::Warrior*> army;
    };
}
#endif /* Noble_hpp */
