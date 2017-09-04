#include <iostream>
#include "winChecker.h"

bool checkRows(int board[], const int BOARD_SIZE) {
	bool flag = false;
	
	for (int element = 0; element < BOARD_SIZE; element+=3) {
		if (board[element] + board[element + 1] + board[element + 2] == 15)
			flag = true;
	}
	return flag;
}

bool checkColumns(int board[], const int BOARD_SIZE) {
	bool flag = false;

	for (int element = 0; element < BOARD_SIZE; element+=4) {
		if (board[element] + board[element - 3] + board[element + 3] == 15)
			flag = true;
	}

	return flag;
}

bool checkUpperDiagonal(int board[]) {

	if (board[0] + board[4] + board[8] == 15)
		return true;
	else
		return false;
}

bool checkLowerDiagonal(int board[]) {

	if (board[2] + board[4] + board[6] == 15)
		return true;
	else
		return false;
}
