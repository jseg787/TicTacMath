#ifndef BOARD_H
#define BOARD_H

void playAMove(int board[], const int BOARD_SIZE);
void display(int board[]);
bool checkForWin(int board[], const int BOARD_SIZE);
bool checkForDraw(int board[], const int BOARD_SIZE);

#endif
