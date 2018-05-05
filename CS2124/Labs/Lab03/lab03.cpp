//
//  rec03.cpp
//  Taimur Ghani
//  9 February 2018
//  This game is a text based minesweeper game.


#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

const int row = 10;
const int col = 10;

struct Tile{
    int adjBombNum;
    bool isBomb = false;
    bool isVisisble;
};

class Minesweeper{
private:
    vector<vector<Tile>> board;
    int gameStatus = 0;
    
public:
    //constructor for the minesweeper board
    Minesweeper(){
        srand(time(NULL));
        board.push_back(vector<Tile>());
        Tile emptyTile;
        for (int r = 0; r < col + 2; r++){
            board[0].push_back(emptyTile);
        }
        for (int r = 0; r < row + 1; r++){
            board.push_back(vector<Tile>());
            board[r+1].push_back(emptyTile);
            for (int c = 0; c < col; c++){
                Tile newTile;
                //newTile.x = r +1;
                //newTile.y = c +1;
                if (rand() % 10 +1 == 1){
                    newTile.isBomb = true;
                }
                else {newTile.isBomb = false;}
                newTile.isVisisble = false;
                board[r+1].push_back(newTile);
            }
            board[r+1].push_back(emptyTile);
        }
        for (int r = 1; r < board.size()-1; r++){
            for (int c = 1; c < board[r].size()-1; c++){
                int numBombs = 0;
                if (board[r][c].isBomb){
                    board[r][c].adjBombNum = -1;
                }
                else{
                    if (board[r][c+1].isBomb == true) {numBombs++;}
                    if (board[r][c-1].isBomb == true) {numBombs++;}
                    if (board[r+1][c].isBomb == true) {numBombs++;}
                    if (board[r-1][c].isBomb == true) {numBombs++;}
                    if (board[r+1][c+1].isBomb == true) {numBombs++;}
                    if (board[r+1][c-1].isBomb == true) {numBombs++;}
                    if (board[r-1][c+1].isBomb == true) {numBombs++;}
                    if (board[r-1][c-1].isBomb == true) {numBombs++;}
                    board[r][c].adjBombNum = numBombs;
                }
            }
        }
    }
    
    //displays the current board
    void display(bool bombs) const{
        if (bombs == true){
            for (int r = 1; r < board.size() - 1; r++){
                for (int c = 1; c < board[0].size() - 1; c++){
                    cout << board[r][c].adjBombNum << "  ";
                }
                cout << endl;
            }
        }
        
        else{
            for (int r = 1; r < board.size() - 1; r++){
                for (int c = 1; c < board[0].size() - 1; c++){
                    if (board[r][c].isVisisble == 0){
                        cout << "X ";
                    }
                    else{
                        cout << board[r][c].adjBombNum << " ";
                    }
                }
                cout << endl;
            }
        }
    }
    
    //returns if the game should keep going or if it is done
    bool done() const{
        return gameStatus;
    }
    
    
    bool validRow(int numRow) const{
        if (numRow > 0 && numRow <= row){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool validCol(int numCol) const{
        if (numCol > 0 && numCol <= col){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isVisible(int row, int col) const{
        return board[row][col].isVisisble;
    }
    
    //this method exexutes the actual game iteslf and checks the conditions as well
    bool play(int row, int col){
        if (board[row][col].isBomb){
            gameStatus = 0;
        }
        else{
            if (board[row][col].adjBombNum != 0){
                board[row][col].isVisisble = true;
            }
            else{
                board[row][col].isVisisble = true;
                if (validRow(row) && validCol(col+1) && board[row][col+1].isVisisble == false){
                    board[row][col].isVisisble = true;
                    play(row,col+1);
                }
                if (validRow(row) && validCol(col-1) && board[row][col-1].isVisisble == false){
                    board[row][col].isVisisble = true;
                    play(row,col-1);
                }
                if (validRow(row+1) && validCol(col+1) && board[row+1][col+1].isVisisble == false){
                    board[row][col].isVisisble = true;
                    play(row+1,col+1);
                }
                if (validRow(row+1) && validCol(col-1) && board[row+1][col-1].isVisisble == false){
                    board[row][col].isVisisble = true;
                    play(row+1,col-1);
                }
                if (validRow(row+1) && validCol(col) && board[row+1][col].isVisisble == false){
                    board[row][col].isVisisble = true;
                    play(row+1,col);
                }
                if (validRow(row+1) && validCol(col-1) && board[row+1][col-1].isVisisble == false){
                    board[row][col].isVisisble = true;
                    play(row+1,col-1);
                }
                if (validRow(row+1) && validCol(col+1) && board[row+1][col+1].isVisisble == false){
                    board[row][col].isVisisble = true;
                    play(row+1,col+1);
                }
                if (validRow(row-1) && validCol(col-1) && board[row-1][col-1].isVisisble == false){
                    board[row][col].isVisisble = true;
                    play(row-1,col-1);
                }
            }
        }
        return !board[row][col].isBomb;
    }
    
};


int main() {
    Minesweeper sweeper;
    // Continue until only invisible cells are bombs
    while (!sweeper.done()) {
        sweeper.display(false); // display board without bombs
        
        int row_sel = -1, col_sel = -1;
        while (row_sel == -1) {
            // Get a valid move
            int r, c;
            cout << "row? ";
            cin >> r;
            if (!sweeper.validRow(r)) {
                cout << "Row out of bounds\n";
                continue;
            }
            cout << "col? ";
            cin >> c;
            if (!sweeper.validCol(c)) {
                cout << "Column out of bounds\n";
                continue;
            }
            if (sweeper.isVisible(r,c)) {
                cout << "Square already visible\n";
                continue;
            }
            row_sel = r;
            col_sel = c;
        }
        // Set selected square to be visible. May effect other cells.
        if (!sweeper.play(row_sel,col_sel)) {
            cout << "Sorry, you died..\n";
            sweeper.display(true); // Final board with bombs shown
            exit(0);
        }
    }
    //Ah! All invisible cells are bombs, so you won!
    cout << "You won!!!!\n";
    sweeper.display(true); // Final board with bombs shown*/
}

