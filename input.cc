#include <iostream>
#include "input.h"
#include "boardchecker.h"

using namespace std;

/// The getAMove function takes an integer 
/// from the user and returns it if its valid 
/// and not on the board

int getAMove(int board[], const int BOARD_SIZE) {
	
	int numberInput;		// to hold the number entered

	do {
		// Prompt the player for an input value
		cout << "Enter an integer you want to place (between 1 and 9): ";
		cin  >> numberInput;
		cout << "You have entered: " << numberInput << endl << endl;
		
		// Display warning if value is invalid
		if (!validate(numberInput))
			cout << "That is an invalid number!\n";
		// Display warning if value is on board
		if (isOnBoard(board, BOARD_SIZE, numberInput))
			cout << "That is already on the board!\n";

	} while (!validate(numberInput) || isOnBoard(board, BOARD_SIZE, numberInput));

	// return the user input
	return numberInput;
}

/// The getASpace function gets a 
/// space from the user

int getASpace(int board[]) {

	int spaceInput;			// To hold the space entered

	do {
		// Prompt user to enter a space
		cout << "Enter the space you would like to place your number " << endl
			 << "(integer between 1 and 9): ";
		cin  >> spaceInput;
		cout << "\nYou have entered: " << spaceInput << endl;
		
		// change number to proper element
		spaceInput -= 1;

		// Display warning if value is invalid
		if (!validate(spaceInput+1))
			cout << "That is an invalid number!\n";

		// Display warning if space is filled
		if (validate(spaceInput+1) && spaceIsFilled(board, spaceInput))
			cout << "That space is already filled\n";

	} while (!validate(spaceInput+1));

	// return the user space
	return spaceInput;
}

/// The validate function checks if the
/// input was in a restricted range

bool validate(int input) {
	// check if the number is within the valid range
	if (input >= 1 && input <= 9) 
		return true;
	else
		return false;
}
