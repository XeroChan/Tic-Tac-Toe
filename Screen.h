//
// Created by UL0265663 on 05.05.2023.
//

#ifndef TIC_TAC_TOE_FINAL_MAYBE_SCREEN_H
#define TIC_TAC_TOE_FINAL_MAYBE_SCREEN_H


#include "Game.h"

class Screen: public Game {
    void ViewBoard() override;

public:
    Screen();
    Screen(const Screen& other) = delete;
    Screen& operator=(const Screen& other) = delete;
};


#endif //TIC_TAC_TOE_FINAL_MAYBE_SCREEN_H
