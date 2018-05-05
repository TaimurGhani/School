/*
 Taimur Ghani
 hw03.cpp
 11 February 2018
 This programs goes through a text file and
 creates warriors, has them battle, and prints
 their status based on the command of the file.
 Warriors have weapons and using classes, encapsulation,
 and data hiding they should be able to follow the
 commands of the input file.
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Warrior{
    
    class Weapon{
    private:
        string name;
        int strength;
    public:
        Weapon(const string& weaponName, int weaponStrength) : name(weaponName), strength(weaponStrength){
        }
        
        void setStrength(int newStrength){
            strength = newStrength;
        }
        
        int getStrength() const{
            return strength;
        }
        
        string getWeaponName() const{
            return name;
        }
    };
    
public:
    Warrior(const string& warriorName, const string& weaponName, int weaponStength) : warriorName(warriorName), warriorWeapon(weaponName, weaponStength){
    }
    
    void setStrength(int newStrength){
        warriorWeapon.setStrength(newStrength);
    }
    
    int getStrength() const{
        return warriorWeapon.getStrength();
    }
    
    string getWarriorName() const{
        return warriorName;
    }
    
    string getWeaponName() const{
        return warriorWeapon.getWeaponName();
    }
    
private:
    string warriorName;
    Weapon warriorWeapon;
    
};

//function prototypes
void printStatus(const vector<Warrior> &warriors);
void warriorsBattle(const string &fighterOne, const string &fighterTwo, vector<Warrior> &warriors);

int main(){
    //reads file and makes sure it opens
    ifstream ifs("warriors.txt");
    if (!ifs){
        cerr << "File did not open" << endl;
        exit(1);
    }
    
    vector<Warrior> warriors;
    string command;
    //raeds in the first word of the line which determines what should happen
    while (ifs >> command){
        //creates a new warrior
        if (command == "Warrior"){
            string warriorName;
            string weaponName;
            int strength;
            ifs >> warriorName >> weaponName >> strength;
            Warrior newWarrior(warriorName, weaponName, strength);
            warriors.push_back(newWarrior);
        }
        //prints out the status of the warriors
        else if (command == "Status"){
            printStatus(warriors);
        }
        //has a battle between two warriors
        else{
            string fighterOne;
            string fighterTwo;
            ifs >> fighterOne >> fighterTwo;
            warriorsBattle(fighterOne, fighterTwo, warriors);
        }
    }
    ifs.close();
}


//prints out all the warriors and their status by going through a list of Warriors
void printStatus(const vector<Warrior> &warriors){
    cout << "There are: " << warriors.size() << " warriors" << endl;
    for (const Warrior &warrior : warriors){
        cout << "Warrior: " << warrior.getWarriorName() << ", weapon: " << warrior.getWeaponName()
        << ", " << warrior.getStrength() << endl;
    }
}

//given the name of two warriors goes through the vector of Warriors and adjusts their atributes accordingly as they fight
void warriorsBattle(const string &fighterOne, const string &fighterTwo, vector<Warrior> &warriors){
    cout << fighterOne << " battles " << fighterTwo << endl;
    size_t indexFighterOne = 0;
    size_t indexFighterTwo = 0;
    //finds the position of the two warriors in the vector
    for (size_t i = 0; i < warriors.size(); i++){
        if (warriors[i].getWarriorName() == fighterOne){
            indexFighterOne = i;
        }
        if (warriors[i].getWarriorName() == fighterTwo){
            indexFighterTwo = i;
        }
    }
    
    int fightOne = warriors[indexFighterOne].getStrength() - warriors[indexFighterTwo].getStrength();
    int fightTwo = warriors[indexFighterTwo].getStrength() - warriors[indexFighterOne].getStrength();
    
    //goes through the cases to determine which warrior won and prints out accordingly
    if (warriors[indexFighterOne].getStrength() > warriors[indexFighterTwo].getStrength()){
        if (warriors[indexFighterTwo].getStrength() == 0){
            cout << "He's dead, " << fighterOne << endl;
        }
        else{
            cout << fighterOne << " defeats " << fighterTwo << endl;
            warriors[indexFighterOne].setStrength(fightOne);
            warriors[indexFighterTwo].setStrength(0);
        }
    }
    else if (warriors[indexFighterOne].getStrength() < warriors[indexFighterTwo].getStrength()){
        if (warriors[indexFighterOne].getStrength() == 0){
            cout << "He's dead, " << fighterTwo << endl;
        }
        else{
            cout << fighterTwo << " defeats " << fighterOne << endl;
            warriors[indexFighterTwo].setStrength(fightTwo);
            warriors[indexFighterOne].setStrength(0);
        }
    }
    else if (fightOne == fightTwo){
        if (warriors[indexFighterOne].getStrength() == 0 && warriors[indexFighterTwo].getStrength() == 0){
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        else{
            cout << "Mutual Annihilation: " << fighterOne << " and " << fighterTwo << " die at each other's hands" << endl;
        }
        warriors[indexFighterOne].setStrength(0);
        warriors[indexFighterTwo].setStrength(0);
    }
}


