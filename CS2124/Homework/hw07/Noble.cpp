//
//  Lord.cpp
//  hw07
//
//  Created by Taimur Ghani on 4/7/18.
//  Copyright © 2018 Taimur Ghani. All rights reserved.
//


#include "Protector.hpp"
#include "Noble.hpp"

Noble::Noble(const string& name) : name(name){}
string Noble::getName() const{
    return name;
}

PersonWithStrengthToFight::PersonWithStrengthToFight (const string& name, int strength) : Noble::Noble(name), strength(strength){}
int PersonWithStrengthToFight::getStrength() const{
    return strength;
}
void PersonWithStrengthToFight::setStrength(int newStrength){
    strength = newStrength;
}



Lord::Lord(const string& name) : Noble::Noble(name){}

void Lord::hires(Protector& protectorName){
    if (!protectorName.isEmployed()){
        army.push_back(&protectorName);
        protectorName.setEmployed(true);
        protectorName.setBoss(this);
    }
    else{
        cout << protectorName.getName() << " is already hired." << endl;
        }
}


void Lord::fire(Protector& protectorName){
    size_t pos = 0;
    for (size_t i = 0; i < army.size(); i++){
        if (army[i] == &protectorName){
            pos = i;
        }
    }
    for (size_t j = pos; j < army.size() - 1; j++){
        army[j] = army[j + 1];
    }
    army.pop_back();
    protectorName.setEmployed(false);
}


void Lord::display() const{
    cout << getName() << " has an army of " << army.size() << endl;
    for (size_t i = 0; i < army.size(); i++){
        cout << "\t" << army[i] -> getName() << ": " << army[i] -> getStrength() << endl;
    }
}



void Lord::battle(Lord& opponent){
    cout << getName() << " battles " << opponent.getName() << endl;
    int strengthOne = 0;
    int strengthTwo = 0;
    for (size_t i = 0; i < army.size(); i ++){
        strengthOne += army[i] -> getStrength();
        //army[i]->makeNoise();
    }
    for (size_t i = 0; i < opponent.army.size(); i ++){
        strengthTwo += opponent.army[i] -> getStrength();
        //army[i]->makeNoise();
    }
    
    if (strengthOne == 0 && strengthTwo == 0){
        cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
    }
    else if (strengthOne == 0){
        cout << "He's dead " << opponent.getName() << endl;;
    }
    else if (strengthTwo == 0){
        cout << "He's dead " << getName() << endl;;
    }
    else if(strengthOne == strengthTwo){
        cout << "Mutual Annihalation: " << getName() << " and " << opponent.getName() <<" die at each other's hands" << endl;
        for (size_t i = 0; i < army.size(); i++){
            army[i]->setStrength(0);
        }
        for (size_t i = 0; i < opponent.army.size(); i++){
            opponent.army[i] -> setStrength(0);
        }
    }
    else if(strengthOne > strengthTwo){
        cout << getName() << " defeats " << opponent.getName() << endl;
        float ratio = 1 - (float)(strengthTwo/strengthOne);
        for (size_t i = 0; i < army.size(); i++){
            army[i] -> setStrength((int)(army[i] -> getStrength() * ratio));
        }
        for (size_t i = 0; i < opponent.army.size(); i++){
            opponent.army[i] -> setStrength(0);
        }
    }
    else{
        cout << opponent.getName() << " defeats " << getName() << endl;
        float ratio = 1 - (float)(strengthOne/strengthTwo);
        for (size_t i = 0; i < opponent.army.size(); i++){
            opponent.army[i] -> setStrength((int)(opponent.army[i] -> getStrength() * ratio));
        }
        for (size_t i = 0; i < army.size(); i++){
            army[i] -> setStrength(0);
        }
    }
    
}

void Lord::battle(PersonWithStrengthToFight& opponent){
    cout << getName() << " battles " << opponent.getName() << endl;
    int strengthOne = 0;
    for (size_t i = 0; i < army.size(); i ++){
        strengthOne += army[i] -> getStrength();
        army[i]->makeNoise();
        cout << endl;
    }
    int strengthTwo = opponent.getStrength();
    if (strengthOne == 0 && strengthTwo == 0){
        cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
    }
    else if (strengthTwo == 0){
        cout << getName() << " defeats " << opponent.getName() << endl;
    }
    else if (strengthOne == 0){
        cout << opponent.getName() << " defeats " << getName() << endl;
    }
    else if (strengthOne == strengthTwo){
        cout << "Mutual Annihalation: " << getName() << " and " << opponent.getName() <<" die at each other's hands" << endl;
        for (size_t i = 0; i < army.size(); i++){
            army[i]->setStrength(0);
        }
        opponent.setStrength(0);
    }
    else if(strengthOne > strengthTwo){
        cout << getName() << " defeats " << opponent.getName() << endl;
        float ratio = 1 - (float)(strengthTwo/strengthOne);
        for (size_t i = 0; i < army.size(); i++){
            army[i] -> setStrength((int)(army[i] -> getStrength() * ratio));
        }
        opponent.setStrength(0);
    }
    else{
        cout << opponent.getName() << " defeats " << getName() << endl;
        float ratio = 1 - (float)(strengthOne/strengthTwo);
        opponent.setStrength((int)(opponent.getStrength() * ratio));
        for (size_t i = 0; i < army.size(); i++){
            army[i] -> setStrength(0);
        }
    }
    
}



