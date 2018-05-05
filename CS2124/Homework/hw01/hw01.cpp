/*
    Taimur Ghani
    hw01.cpp
    27 January 2018
    This program will read in a file and decrypt it using Casesar
    Cypher. The first line of input for the file will tell
    how many times to "rotate" each letter. The lines in the file
    will be reversed to decrypt the file.
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

//takes a character and the number of rotations and decrypts it
char decryptCharacter (char initialChar, int rotate){
    //checks to see if the character is lowercase
    if (islower(initialChar)){
        char newChar = char(int(initialChar) - (rotate%26));
        //checks to see if the new charactere has to loop over after 'z' or loop under before 'a'
        if (newChar >= 'a' && newChar <= 'z'){
            return newChar;
        }
        else if (newChar > 'z'){
            return char(int(newChar) - 26);
        }
        else if (newChar < 'a'){
            return char(int(newChar) + 26);
        }
    }
    //if the character is not lowercase return the intial character
    return initialChar;
}

//takes a string and the number of rotations and decrypts it
void decryptString (string &intialString, int rotate){
    for (char &item : intialString){
        item = decryptCharacter(item, rotate);
    }
    
}

int main(int argc, const char * argv[]) {
    vector <string> input;

    string line;
    ifstream ifs("encrypted.txt");
    //checks to see that the file opened
    if (!ifs){
        cerr << "failed to open file" << endl;
        exit(1);
    }
    //appends each line of the file to the vector 'input' as a string
    while (getline(ifs, line)) {
        input.push_back(line);
    }
    
    //decrypts all the strings by going throught the vector of lines
    for (size_t i = input.size()-1; i > 0; i--){
        decryptString(input[i], stoi(input[0]));
        cout << input[i] << endl;
    }
    
}

