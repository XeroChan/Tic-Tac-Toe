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
private:
    vector<Players*> List;
protected:
    Board* board;
public:
    Game();
    ~Game();
    Game(const Game& other) = delete;
    Game& operator=(const Game& other) = delete;
    void play();
    void InitPlayers();
    int InitBoard();
    virtual void ViewBoard() = 0;
};


#endif //TIC_TAC_TOE_FINAL_MAYBE_GAME_H
