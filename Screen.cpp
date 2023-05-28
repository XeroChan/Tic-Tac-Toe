//
// Created by UL0265663 on 05.05.2023.
//

#include "Screen.h"
#include <iostream>
using namespace std;

Screen::Screen() : Game() {
    initPlayers();
}

void Screen::ViewBoard() {
    cout << "Screen view:\n";
    board->printBoard();
}

void Screen::createPlayers() {
    cout << "Enter the number of players who are going to play:\n";
    cin >> players;

    for (int i = 0; i < players; i++) {
        char symbol;
        string name = "Player " +  to_string(i + 1);
        cout << name << " chooses symbol: ";
        cin >> symbol;
        Players* player = new Human(symbol, *board);
        List.push_back(player);
    }
}

void Screen::createBots() {
    cout << "Enter the number of bots to play against:\n";
    cin >> bots;

    for (int i = 0; i < bots; i++) {
        char symbol;
        string name = "Bot " +  to_string(i + 1);
        cout << name << " chooses symbol: ";
        cin >> symbol;
        Players* player = new Computer(symbol, *board);
        List.push_back(player);
    }
}

void Screen::initPlayers() {
    createPlayers();
    createBots();
}
