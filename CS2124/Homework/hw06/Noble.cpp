//
//  Noble.cpp
//  hw06
//
//  Created by Taimur Ghani on 3/22/18.
//  Copyright © 2018 Taimur Ghani. All rights reserved.
//
#include "Warrior.hpp"
#include "Noble.hpp"

namespace WarriorCraft{
    Noble::Noble (const string& name) : name(name) {}
    void Noble::hire(Warrior& warriorName){
        if (!warriorName.isEmployed()){
            army.push_back(&warriorName);
            warriorName.setEmployed(true);
            warriorName.setBoss(this);
        }
        else{
            cout << warriorName.getName() << " is already hired." << endl;
        }
    }

    void Noble::fire(Warrior& warriorName){
        size_t pos = 0;
        for (size_t i = 0; i < army.size(); i++){
            if (army[i] == &warriorName){
                pos = i;
            }
        }
        for (size_t j = pos; j < army.size() - 1; j++){
            army[j] = army[j + 1];
        }
        army.pop_back();
        warriorName.setEmployed(false);
    }

    void Noble::display() const{
        cout << name << " has an army of " << army.size() << endl;
        for (size_t i = 0; i < army.size(); i++){
            cout << "\t" << army[i] -> getName() << ": " << army[i] -> getStrength() << endl;
        }
    }
    

    void Noble::battle(Noble& opponent){
        cout << name << " battles " << opponent.name << endl;
        int strengthOne = 0;
        int strengthTwo = 0;
        for (size_t i = 0; i < army.size(); i ++){
            strengthOne += army[i] -> getStrength();
        }
        for (size_t i = 0; i < opponent.army.size(); i ++){
            strengthTwo += opponent.army[i] -> getStrength();
        }
        
        if (strengthOne == 0 && strengthTwo == 0){
            cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
        }
        else if (strengthOne == 0){
            cout << "He's dead " << opponent.name << endl;;
        }
        else if (strengthTwo == 0){
            cout << "He's dead " << name << endl;;
        }
        else if(strengthOne == strengthTwo){
            cout << "Mutual Annihalation: " << name << " and " << opponent.name <<" die at each other's hands" << endl;
            for (size_t i = 0; i < army.size(); i++){
                army[i]->setStrength(0);
            }
            for (size_t i = 0; i < opponent.army.size(); i++){
                opponent.army[i] -> setStrength(0);
            }
        }
        else if(strengthOne > strengthTwo){
            cout << name << " defeats " << opponent.name << endl;
            float ratio = 1 - (float)(strengthTwo/strengthOne);
            for (size_t i = 0; i < army.size(); i++){
                army[i] -> setStrength((int)(army[i] -> getStrength() * ratio));
            }
            for (size_t i = 0; i < opponent.army.size(); i++){
                opponent.army[i] -> setStrength(0);
            }
        }
        else{
            cout << opponent.name << " defeats " << name << endl;
            float ratio = 1 - (float)(strengthOne/strengthTwo);
            for (size_t i = 0; i < opponent.army.size(); i++){
                opponent.army[i] -> setStrength((int)(opponent.army[i] -> getStrength() * ratio));
            }
            for (size_t i = 0; i < army.size(); i++){
                army[i] -> setStrength(0);
            }
        }
        
    }
    
    string Noble::getName() const{
        return name;
    }
    
    ostream& operator<<(ostream& os, Noble::Noble& noble){
        os << noble.name << " has an army of " << noble.army.size() << endl;
        for (size_t i = 0; i < noble.army.size(); i++){
            cout << "\t" << noble.army[i] -> getName() << ": " << noble.army[i] -> getStrength() << endl;
        }
        return os;
    }
}
