/*
    rec02.cpp
    Taimur Ghani
    2 February 2018
    This programs reads in a file of chemical formulas with their names.
    Using a struct for these formulas it then prints out the formula
    with all the corresponding names for that molecular formula.
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Formula {
    vector<string> names;
    int numCarbon;
    int numHydrogen;
};

//function prototypes
size_t findInList(const int carbonAtoms, const int hydrogenAtoms, const vector<Formula>& vf);
void printSortedFormulas (const vector<Formula>& vf, const int maxCarbons);


int main(int argc, const char * argv[]) {
    
    vector <Formula> vf;
    string name;
    char Carbon;
    char Hydrogen;
    int cNum;
    int hNum;
    
    ifstream ifs("formulas.txt");
    if (!ifs){
        cerr << "File not open" << endl;
    }
    
    int maxCarbons = 0;
    while (ifs >> name >> Carbon >> cNum >> Hydrogen >> hNum){
        Formula aFormula;
        aFormula.numCarbon = cNum;
        aFormula.numHydrogen = hNum;
        
        //adds the name of the chemical formula if the molecular formula is the same to the vector
        //of names for that formula. Otherwise adds a new entry into the vector of Formulas list
        size_t position = findInList(aFormula.numCarbon, aFormula.numHydrogen, vf);
        if (position < vf.size()){
            vf[position].names.push_back(name);
        }
        else{
            aFormula.names.push_back(name);
            vf.push_back(aFormula);
        }
        
        //keeps track of maxCarbon atom number
        if (aFormula.numCarbon > maxCarbons) {maxCarbons = aFormula.numCarbon;}
    }
    
    printSortedFormulas(vf, maxCarbons);
    ifs.close();
}



//this function returns the posisition of the chemical formula if found in the vector. If
//not found then it returns the size of the vector.
size_t findInList(const int carbonAtoms, const int hydrogenAtoms, const vector<Formula>& vf){
    for (size_t i = 0; i < vf.size(); i++){
        if (vf[i].numCarbon == carbonAtoms && vf[i].numHydrogen == hydrogenAtoms){
            return i;
        }
    }
    return vf.size();
}

//goes through a loop up to the number of max carbons and prints out the chemical
//formulas in sorted order based on the number of carbons
void printSortedFormulas (const vector<Formula>& vf, int maxCarbons){
    for (int i = 0; i <= maxCarbons; i++){
        for (size_t j= 0; j < vf.size(); j++){
            string output;
            if (vf[j].numCarbon == i){
                for (size_t k = 0; k < vf[j].names.size(); k++){
                    output = output + vf[j].names[k] + " ";
                }
                cout << 'C' << vf[j].numCarbon << 'H' << vf[j].numHydrogen << ' ' << output << endl;
            }
        }
    }
}

