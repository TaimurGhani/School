//
/*
 Taimur Ghani
 GameOfLife.cpp
 This program will be an implementation of Conway's Game of Life
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

//Method that prints out the next generation
void nextGeneration(vector<vector<char>> &board){
    //creates a copy of the original board passed
    vector<vector<char>> boardCopy;
    for (int i = 0; i < board.size(); i++){
        boardCopy.push_back(vector<char>());
        for (int j = 0; j < board[i].size(); j++){
            boardCopy[i].push_back(board[i][j]);
        }
    }
    
    //finds number of neighbors and changes accordingly
    for (int i = 1; i < board.size()-1; i++){
        for (int j = 1; j < board[i].size()-1; j++){
            int numNeighbors = 0;
            if (board[i][j+1] == '*') {numNeighbors++;}
            if (board[i][j-1] == '*') {numNeighbors++;}
            if (board[i+1][j] == '*') {numNeighbors++;}
            if (board[i-1][j] == '*') {numNeighbors++;}
            if (board[i+1][j+1] == '*') {numNeighbors++;}
            if (board[i+1][j-1] == '*') {numNeighbors++;}
            if (board[i-1][j+1] == '*') {numNeighbors++;}
            if (board[i-1][j-1] == '*') {numNeighbors++;}
            if ((numNeighbors<2 || numNeighbors>3) && (board[i][j] == '*')){
                boardCopy[i][j] = ' ';
            }
            if (board[i][j] == ' ' && numNeighbors == 3){
                boardCopy[i][j] = '*';
            }
        }
    }
    
    
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[i].size(); j++){
            cout << boardCopy[i][j];
        }
        cout<<endl;
    }
    
    board = boardCopy;
}


int main() {
    vector<vector<char>> board;
    vector <string> rows;
    
    ifstream ifs("life.txt");
    if (!ifs){
        cerr << "failed to open file" << endl;
        exit(1);
    }
    
    string lifeStatus;
    while (ifs >> lifeStatus) {
        rows.push_back(lifeStatus);
    }
    board.push_back(vector<char>());
    for (int i = 0; i < rows[0].length() + 2; i++){
        board[0].push_back(' ');
    }
    for (int i = 0; i < rows.size(); i++) {
        board.push_back(vector<char>());
        board[i+1].push_back(' ');
        for (int j = 0; j < rows[0].length(); j++){
            if (rows[i][j] == ('-')) {board[i+1].push_back(' ');}
            else if (rows[i][j] == ('*')) {board[i+1].push_back('*');}
        }
        board[i+1].push_back(' ');
    }
    
    cout << "Initial Board" << endl;
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[i].size(); j++){
            cout << board[i][j];
        }
        cout<<endl;
    }
    cout << "Enter the Number Of Generations you want to see:" << endl;
    int numGenerations;
    cin >>  numGenerations;
    for (int i = 1; i<numGenerations + 1; i++){
        cout << "Generation " << i << endl;
        nextGeneration(board);
    }
    
}


