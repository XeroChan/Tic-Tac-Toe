//
// Created by Maciej on 05.04.2023.
//

#ifndef TIC_TAC_TOE_FINAL_MAYBE_PlayersS_H
#define TIC_TAC_TOE_FINAL_MAYBE_PlayersS_H


class Board;

class Players {
public:
    explicit Players(char);
    [[nodiscard]] char getSymbol() const;
    virtual ~Players();
    Players(const Players& other) = delete;
    Players& operator=(const Players& other) = delete;
    virtual void makeMove() = 0;
protected:
    char symbol;
};

class Human : public Players {
public:
    Human(char, Board&);
    Human(const Human& other) = delete;
    Human& operator=(const Human& other) = delete;
    void makeMove() override;
private:
    Board& board;
};

class Computer : public Players {
public:
    Computer(char, Board&);
    Computer(const Computer& Computer) = delete;
    Computer& operator=(const Computer& other) = delete;
    void makeMove() override;
private:
    Board& board;
};


#endif //TIC_TAC_TOE_FINAL_MAYBE_PlayersS_H
