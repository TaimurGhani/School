//
//  hw04.cpp
//  hw04
//
//  Created by Taimur Ghani on 2/23/18.
//  Copyright © 2018 Taimur Ghani. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Warrior{
public:
    Warrior (const string& name, int strength) : name(name), strength(strength){}
    
    string getName(){
        return name;
    }
    
    int getStrength(){
        return strength;
    }
    
    void setStrength(int newStrength){
        strength = newStrength;
    }
    
    void setEmployed(bool boolean){
        employed = boolean;
    }
    
    bool isEmployed(){
        return employed;
    }
    
private:
    string name;
    int strength;
    bool employed;
};



class Noble{
public:
    Noble (const string& name) : name(name) {}
    
    void hire(Warrior& warriorName){
        if (!warriorName.isEmployed()){
            army.push_back(&warriorName);
            warriorName.setEmployed(true);
        }
        else{
            cout << warriorName.getName() << " is already hired." << endl;
        }
    }
    
    void fire(Warrior& warriorName){
        cout << warriorName.getName() << " , you're fired! -- " << name << endl;
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
    
    void display(){
        cout << name << " has an army of " << army.size() << endl;
        for (size_t i = 0; i < army.size(); i++){
            cout << "\t" << army[i] -> getName() << ": " << army[i] -> getStrength() << endl;
        }
    }
    
    void battle(Noble& opponent){
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
private:
    string name;
    vector<Warrior*> army;
};

int main(){
    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");
    
    Warrior cheetah("Tarzan", 10);
    Warrior wizard("Merlin", 15);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);
    
    jim.hire(nimoy);
    lance.hire(theGovernator);
    art.hire(wizard);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(cheetah);
    
    jim.display();
    lance.display();
    art.display();
    linus.display();
    billie.display();
    
    art.fire(cheetah);
    art.display();
    
    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);
}
