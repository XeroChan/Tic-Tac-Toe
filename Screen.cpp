//
// Created by UL0265663 on 05.05.2023.
//

#include "Screen.h"
#include <iostream>
using namespace std;

Screen::Screen() = default;

void Screen::ViewBoard() {
    cout << "Screen view:\n";
    board->printBoard();
}

void Screen::enterPlayers() {
    cout << "Enter number of players who going to play:\n";
    cin >> players;
    for(int i=0; i<players; i++){
        string name = "Player ";
        name+= to_string(i+1);
        cout << name << " chooses symbol: ";
        cin >> symbol;
        Players* player = new Human(symbol, *board);
        List.push_back(player);
    }
}

void Screen::enterBots() {
    cout << "Enter number of bots to play against:\n";
    cin >> bots;
    for(int i=0; i<bots; i++){
        string name = "Bot ";
        name+= to_string(i+1);
        cout << name << " chooses symbol: ";
        cin >> symbol;
        Players* player = new Computer(symbol, *board);
        List.push_back(player);
    }
}

