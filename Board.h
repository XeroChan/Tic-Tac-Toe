//
// Created by Maciej on 05.04.2023.
//

#ifndef TIC_TAC_TOE_FINAL_MAYBE_BOARD_H
#define TIC_TAC_TOE_FINAL_MAYBE_BOARD_H


class Board {
private:
    char** boardFields;
    int n;
public:
    explicit Board(int);
    ~Board();
    Board(const Board& Computer) = delete;

    Board();

    Board& operator=(const Board& other) = delete;
    void setBoardField(int, int, char);
    char getBoardField(int, int);
    [[nodiscard]] int getN() const;
    void printBoard();
    bool isFull();
    bool checkWin(char);
};


#endif //TIC_TAC_TOE_FINAL_MAYBE_BOARD_H
