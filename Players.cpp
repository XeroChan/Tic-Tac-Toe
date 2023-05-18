//
// Created by Maciej on 05.04.2023.
//

#include <iostream>
#include <random>
#include "Players.h"
#include "Board.h"
using namespace std;

using namespace std;

Players::Players(char symbol) : symbol(symbol){};

Players::~Players() = default;

char Players::getSymbol() const { return symbol; }

Human::Human(char symbol, Board& board) : Players(symbol), board(board) {}

void Human::makeMove() {

    int row, col;
    cout << symbol << "'s turn\n Enter the field as row[space]column from range (1-" << board.getN() << "): ";
    cin >> row >> col;
    row--;
    col--;
    while (row < 0 || row >= board.getN() || col < 0 || col >= board.getN() || board.getBoardField(row, col) != ' ') {
        cout << "Invalid move. Enter the field as row[space]column from range (1-" << board.getN() << "): ";
        cin >> row >> col;
        row--;
        col--;
    }
    system("cls");
    board.setBoardField(row, col, symbol);
}

Computer::Computer(char symbol, Board& board) : Players(symbol), board(board) {}
void Computer::makeMove() {

    mt19937 rng(random_device{}());

    uniform_int_distribution<int> dist(0, board.getN()-1);

    int randI, randJ;
    do {
        randI = dist(rng);
        randJ = dist(rng);
    } while (board.getBoardField(randI, randJ) != ' ');
    board.setBoardField(randI, randJ, symbol);
}




