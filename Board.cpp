//
// Created by Maciej on 05.04.2023.
//

#include <iostream>
#include "Board.h"
using namespace std;

Board::Board(int size) {
    n = size;
    boardFields = new char*[n];
    for(int i = 0; i < n; i++){
        boardFields[i] = new char[n];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            boardFields[i][j] = ' ';
        }
    }
}

Board::~Board() {
    for(int i = 0; i < n; i++){
        delete[] boardFields[i];
    }
    delete[] boardFields;
}

void Board::printBoard() {
    cout << "   ";
    for(int j = 1; j <= n; j++){
        if(j>=10){
            cout << " " << j << " ";
        }else{
            cout << "  " << j << " ";
        }
    }
    cout << endl;

    cout << "  +";
    for(int j = 1; j <= n; j++){
        cout << "---+";
    }
    cout << endl;

    for(int i = 1; i <= n; i++){
        if(i>=10){
            cout << i << " |";
        }else{
            cout << " " << i << " |";
        }

        for(int j = 1; j <= n; j++){
            cout << " " << boardFields[i-1][j-1] << " |";
        }

        cout << endl << "  +";
        for(int j = 1; j <= n; j++){
            cout << "---+";
        }
        cout << endl;
    }
}


void Board::setBoardField(int r, int c, char val) {
    boardFields[r][c] = val;
}

char Board::getBoardField(int r, int c) {
    return boardFields[r][c];
}

bool Board::checkWin(char player) {
    int sPoz = 0, sPion = 0, sPrzek = 0, sPrzekRev = 0;
    bool won = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (boardFields[i][j] == player && !won) {
                for (int w = i - 1; w <= i + 1; w++) {
                    for (int k = j - 1; k <= j + 1; k++) {
                        if (w >= 0 && w < n && k >= 0 && k < n) {
                            if (boardFields[w][k] == player && (w != i || k != j)) {
                                if (w==i+1 && k==j+1 || (w==i-1 && k==j-1)) sPrzek++;
                                if ((w==i-1 && k==j+1) || (w==i+1 && k==j-1)) sPrzekRev++;
                                if (w == i) sPoz++;
                                if (k == j) sPion++;
                            }
                        }
                    }
                }
                if (sPoz == 2 || sPion == 2 || sPrzek == 2 || sPrzekRev == 2) {
                    won = true;
                }
                sPrzek = 0;
                sPrzekRev = 0;
                sPion = 0;
                sPoz = 0;
            }
        }
    }
    return won;
}

bool Board::isFull() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(boardFields[i][j]==' ') return false;
        }
    }
    return true;
}

int Board::getN() const {
    return n;
}

