//
// Created by Maciej on 05.04.2023.
//

#ifndef TIC_TAC_TOE_FINAL_MAYBE_GAME_H
#define TIC_TAC_TOE_FINAL_MAYBE_GAME_H


#include "Board.h"
#include "Players.h"
#include <vector>

using namespace std;

class Game {
protected:
    Board* board;
    int players, bots;
    char symbol;
    vector<Players*> List;
public:
    Game();
    ~Game();
    Game(const Game& other) = delete;
    Game& operator=(const Game& other) = delete;
    void play();
    void InitPlayers();
    static int InitBoard();
    virtual void ViewBoard() = 0;
    virtual void enterPlayers() = 0;
    virtual void enterBots() = 0;
};


#endif //TIC_TAC_TOE_FINAL_MAYBE_GAME_H
