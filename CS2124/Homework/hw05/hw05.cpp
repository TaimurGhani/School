/*
    hw05.cpp
    Taimur Ghani
    28 Feb 2018
    This program is for homework 5
    in OOP - CS2124
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Warrior{
public:
    Warrior (const string& name, int strength) : name(name), strength(strength){}
    
    string getName() const{
        return name;
    }
    
    int getStrength() const{
        return strength;
    }
    
    void setStrength(int newStrength) {
        strength = newStrength;
    }
    
    void setEmployed(bool boolean){
        employed = boolean;
    }
    
    bool isEmployed() const{
        return employed;
    }
    
private:
    string name;
    int strength;
    bool employed = false;
};



class Noble{
public:
    Noble (const string& name) : name(name) {}
    
    string getName() const{
        return name;
    }
    
    vector<Warrior*> getWorkers() const{
        return army;
    }
    
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
        cout << "You don't work for me anymore " << warriorName.getName() << "! -- "  << name << endl;
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
    
    void display() const{
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
            float ratio = 1 - float(strengthTwo)/float(strengthOne);
            for (size_t i = 0; i < army.size(); i++){
                army[i] -> setStrength((int)((army[i] -> getStrength()) * ratio));
            }
            for (size_t i = 0; i < opponent.army.size(); i++){
                opponent.army[i] -> setStrength(0);
            }
        }
        else{
            cout << opponent.name << " defeats " << name << endl;
            float ratio = 1 - float(strengthOne)/float(strengthTwo);
            for (size_t i = 0; i < opponent.army.size(); i++){
                opponent.army[i] -> setStrength((int)((opponent.army[i] -> getStrength()) * ratio));
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



int main() {
    vector<Noble*> nobles;
    vector<Warrior*> freeWarriors;
    vector<string> warriorNames;
    string command;
    bool flag;
    ifstream ifs("nobleWarriors.txt");
    if (!ifs){
        cerr << "failed to open file" << endl;
        exit(1);
    }
    
    while (ifs >> command){
        if (command == "Warrior"){
            string warriorName;
            int warriorStrength;
            ifs >> warriorName >> warriorStrength;
            flag = false;
            for (size_t i = 0; i < warriorNames.size(); i++){
                if (warriorNames[i] == warriorName){
                    cout << "The name " << warriorName << " is already used" << endl;
                    flag = true;
                }
            }
            if (flag == false){
                Warrior* newWarrior = new Warrior(warriorName, warriorStrength);
                freeWarriors.push_back(newWarrior);
                warriorNames.push_back(warriorName);
            }
        }
        else if (command == "Noble"){
            string nobleName;
            ifs >> nobleName;
            flag = false;
            for (size_t i = 0; i < nobles.size(); i++){
                if (nobles[i]->getName() == nobleName){
                    cout << "The name " << nobleName << " is already used" << endl;
                    flag = true;
                }
            }
            if (flag == false){
                Noble* newNoble = new Noble(nobleName);
                nobles.push_back(newNoble);
            }
        }
        else if (command == "Hire"){
            string nobleName;
            string warriorName;
            size_t spot=0;
            ifs >> nobleName >> warriorName;
            bool flagOne = false;
            bool flagTwo = false;
            for (size_t i = 0; i < nobles.size(); i++){
                if (nobles[i]->getName() == nobleName){
                    flagOne = true;
                    for (size_t j = 0; j < freeWarriors.size(); j++){
                        if(freeWarriors[j]->getName() == warriorName){
                            spot = j;
                            flagTwo = true;
                            nobles[i]->hire(*freeWarriors[j]);
                        }
                    }
                }
            }
            if (flagTwo == true){
                for (size_t i = spot; i < freeWarriors.size() - 1; i++){
                    Warrior* temp = freeWarriors[i];
                    freeWarriors[i]= freeWarriors[i + 1];
                    freeWarriors[i+1] = temp;
                }
                //delete freeWarriors[freeWarriors.size()-1];
                freeWarriors[freeWarriors.size()-1] = NULL;
                freeWarriors.pop_back();
            }
            if (flagOne == false){
                cout << "There is no noble with name: " << nobleName << endl;
            }
            if (flagTwo == false){
                cout << "There is no unhired warrior with name: " << warriorName << endl;
            }
        }
        
        else if (command == "Fire"){
            string nobleName;
            string warriorName;
            ifs >> nobleName >> warriorName;
            bool flagOne = false;
            bool flagTwo = false;
            for (size_t i = 0; i < nobles.size(); i++){
                if (nobles[i]->getName() == nobleName){
                    flagOne = true;
                    for (size_t j = 0; j < (nobles[i]->getWorkers()).size(); j++){
                        if((nobles[i]->getWorkers())[j]->getName() == warriorName){
                            flagTwo = true;
                            nobles[i]->fire(*(nobles[i]->getWorkers())[j]);
                            freeWarriors.push_back((nobles[i]->getWorkers())[j]);
                        }
                    }
                }
            }
            if (flagOne == false){
                cout << "There is no noble with name: " << nobleName << endl;;
            }
            if (flagTwo == false){
                cout << "There is no warrior in " << nobleName << "'s army with name: " << warriorName << endl;
            }
        }
        
        else if (command == "Status"){
            bool flagN = false;
            bool flagW = false;
            cout << "Status:" << endl;
            cout << "=======" << endl;
            cout << "Nobles:" << endl;
            if (nobles.size() == 0){
                cout << "\t NONE" << endl;
                flagN = true;
            }
            else{
                for (size_t i = 0; i < nobles.size(); i++){
                    if (nobles[i] != NULL){
                        nobles[i] -> display();
                        flagN = true;
                    }
                }
            }
            if (!flagN){
                cout << "\t NONE" << endl;
            }
            cout << "Unemployed Warriors:" << endl;
            if (freeWarriors.size() == 0){
                cout << "\t NONE" << endl;
                flagW = true;
            }
            else{
                for (size_t i = 0; i < freeWarriors.size(); i++){
                    if (freeWarriors[i] != NULL){
                        cout << freeWarriors[i]->getName() << ": " << freeWarriors[i]->getStrength() << endl;
                        flagW = true;
                    }
                }
            }
            if (!flagW){
                cout << "\t NONE" << endl;
            }
        }
        
        else if (command == "Clear"){
            for (size_t i = nobles.size(); i > 0; i--){
                for (size_t j = 1; j < (nobles[i-1]->getWorkers()).size()+1; j++){
                    (nobles[i-1]->getWorkers())[j-1] = NULL;
                    delete  (nobles[i-1]->getWorkers())[j-1];
                }
                nobles[i-1] = NULL;
                delete nobles[i-1];
            }
            for (size_t i = 0; i < freeWarriors.size(); i++){
                freeWarriors[i] = NULL;
                delete freeWarriors[i];
            }
        }
        else{
            string nobleOne;
            string nobleTwo;
            ifs >> nobleOne >> nobleTwo;
            bool flagOne = false;
            bool flagTwo = false;
            for (size_t i = 0; i < nobles.size(); i++){
                if (nobles[i]->getName() == nobleOne){
                    flagOne = true;
                    for (size_t j = 0; j < nobles.size(); j++){
                        if(nobles[j]->getName() == nobleTwo){
                            flagTwo = true;
                            nobles[i]->battle(*nobles[j]);
                        }
                    }
                }
            }
            if (flagOne == false){
                cout << "There is no noble with name: " << nobleOne << endl;;
            }
            if (flagTwo == false){
                cout << "There is no noble with name: " << nobleTwo << endl;
            }
            
        }
    }
    
}



