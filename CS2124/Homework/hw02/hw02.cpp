/*
    Taimur Ghani
    hw02.cpp
    5 February 2018
    This programs goes through a text file and
    creates warriors, has them battle, and prints
    their status based on the command of the file.
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Warrior{
    string name;
    int strength;
};

//function prototypes
void makeWarrior(const string &name, int strength, vector<Warrior> &warriors);
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
            string name;
            int strength;
            ifs >> name >> strength;
            makeWarrior(name, strength, warriors);
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
}

//takes the name and the strength and creates a new Warrior and adds it to a vector of Warriors
void makeWarrior(const string &name, int strength, vector<Warrior> &warriors){
    Warrior aWarrior;
    aWarrior.name = name;
    aWarrior.strength = strength;
    warriors.push_back(aWarrior);
}

//prints out all the warriors and their status by going through a list of Warriors
void printStatus(const vector<Warrior> &warriors){
    cout << "There are: " << warriors.size() << " warriors" << endl;
    for (const Warrior &warrior : warriors){
        cout << "Warrior: " << warrior.name << ", strength: " << warrior.strength << endl;
    }
}

//given the name of two warriors goes through the vector of Warriors and adjusts their atributes accordingly as they fight
void warriorsBattle(const string &fighterOne, const string &fighterTwo, vector<Warrior> &warriors){
    cout << fighterOne << " battles " << fighterTwo << endl;
    size_t indexFighterOne = 0;
    size_t indexFighterTwo = 0;
    //finds the position of the two warriors in the vector
    for (size_t i = 0; i < warriors.size(); i++){
        if (warriors[i].name == fighterOne){
            indexFighterOne = i;
        }
        if (warriors[i].name == fighterTwo){
            indexFighterTwo = i;
        }
    }
    
    int fightOne = warriors[indexFighterOne].strength - warriors[indexFighterTwo].strength;
    int fightTwo = warriors[indexFighterTwo].strength - warriors[indexFighterOne].strength;
    
    //goes through the cases to determine which warrior won and prints out accordingly
    if (warriors[indexFighterOne].strength > warriors[indexFighterTwo].strength){
        if (warriors[indexFighterTwo].strength == 0){
            cout << "He's dead, " << fighterOne << endl;
        }
        else{
            cout << fighterOne << " defeats " << fighterTwo << endl;
            warriors[indexFighterOne].strength = fightOne;
            warriors[indexFighterTwo].strength = 0;
        }
    }
    else if (warriors[indexFighterOne].strength < warriors[indexFighterTwo].strength){
        if (warriors[indexFighterOne].strength == 0){
            cout << "He's dead, " << fighterTwo << endl;
        }
        else{
            cout << fighterTwo << " defeats " << fighterOne << endl;
            warriors[indexFighterTwo].strength = fightTwo;
            warriors[indexFighterOne].strength = 0;
        }
    }
    else if (fightOne == fightTwo){
        if (warriors[indexFighterOne].strength == 0 && warriors[indexFighterTwo].strength == 0){
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        else{
            cout << "Mutual Annihilation: " << fighterOne << " and " << fighterTwo << " die at each other's hands" << endl;
        }
        warriors[indexFighterOne].strength = 0;
        warriors[indexFighterTwo].strength = 0;
    }
}
