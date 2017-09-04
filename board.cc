#include <iostream>
#include "board.h"
#include "input.h"
#include "boardchecker.h"
#include "winChecker.h"

using namespace std;

/// The playAMove function puts a player's
/// move on the board.

void playAMove(int board[], const int BOARD_SIZE) {

	int playerInput;			// to hold the player's number input
	int playerSpace;			// to hold the player's space
	
	// Set the player's input
	playerInput = getAMove(board, BOARD_SIZE);
	
	// Set the players space
	playerSpace = getASpace(board);

	// Put the number on the board
	board[playerSpace] = playerInput;

	display(board);
}



/// The display function shows the current
/// state of the board.

void display(int board[]) {
	// First row
	spacePrint(board, 0); cout << " | ";
   	spacePrint(board, 1); cout << " | "; 
	spacePrint(board, 2); cout << endl;

	// Second row
	cout << "---------"  << endl;
	spacePrint(board, 3); cout << " | ";
   	spacePrint(board, 4); cout << " | "; 
	spacePrint(board, 5); cout << endl;

	// Third row
	cout << "---------" << endl;
	spacePrint(board, 6); cout << " | ";
   	spacePrint(board, 7); cout << " | "; 
	spacePrint(board, 8); cout << endl;
		
}

/// The checkForWin function checks if there is 
/// a winner and returns a boolean.

bool checkForWin(int board[], const int BOARD_SIZE) {
	bool isWinner = false;

	if (checkRows(board, BOARD_SIZE))
		isWinner = true;
	else if (checkColumns(board, BOARD_SIZE))
		isWinner = true;
	else if (checkUpperDiagonal(board))
		isWinner = true;
	else if (checkLowerDiagonal(board))
		isWinner = true;

	return isWinner;
}

bool checkForDraw(int board[], const int BOARD_SIZE) {
	bool isDraw = false;

	// check if there are any empty spaces
	for(int element = 0; element < BOARD_SIZE; element++) {
		if (board[element] == -10)
			return isDraw;
	}

	// check if ithere is a winner
	if (!checkForWin(board, BOARD_SIZE)) {
		isDraw = true;
		return isDraw;
	}
	else
		return isDraw;
}
