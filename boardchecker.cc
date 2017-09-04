#include <iostream>
#include <string>
#include "boardchecker.h"

using namespace std;

/// The isOnBoard function check if the users
/// input number is already on the board

bool isOnBoard(int board[], const int BOARD_SIZE, int inputNumber) {
	
	bool onBoard = false;		// Flag to change if number is on board

	// go through the array to check if the number is on the board
	for (int element = 0; element < BOARD_SIZE; element++) {
		if (inputNumber == board[element])
			onBoard = true;
	}
	
	// return the flag
	return onBoard;
}

/// The spaceIsFilled function checks if the
/// desired user space is filled

bool spaceIsFilled(int board[], int playerSpace) {

	bool isFilled = false;		// Flag to chage if space is filled
	
	// Check if the space is filled (-10 is an empty space)
	if (board[playerSpace] != -10)
		isFilled = true;

	// return the flag
	return isFilled;
}

/// The spacePrint funtion checks if the desired
/// board space has a value and prints relevent
/// output for each case

void spacePrint(int board[], int space) {

	if (!spaceIsFilled(board, space))
		cout << " ";
	else
		cout << board[space];
}
