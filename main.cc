#include <iostream>
#include <string>
#include "board.h"
#include "input.h"

using namespace std;

int main() {

	const int BOARD_SIZE = 9;		// Hold the board size
	int board[BOARD_SIZE];			// The board
	int playerNumber = 0;			// To hold the current player
	string winner = "";				// To hold the winner

	// initialize all elements to -10 (to be considered empty)
	for (int element = 0; element < BOARD_SIZE; element++)
		board[element] = -10;

	cout << "Welcome to tic-tac-math!\n" 
		 << "The goal of this game is to get 3 numbers\n"
		 << "in a row whose sum is 15!\n"
		 << "just put a number into the spaces listed "
		 << "on the sample board\n\n";

	cout << "1 | 2 | 3" << endl
		 << "---------" << endl
		 << "4 | 5 | 6" << endl
		 <<"----------" << endl
		 << "7 | 8 | 9" << endl;

	// play game while there is no winner
	while (!checkForWin(board, BOARD_SIZE) && !checkForDraw(board, BOARD_SIZE)) {
	
		// increment player number
		playerNumber++;

		// check which player's turn it is
		if (playerNumber % 2 == 0)
			cout << "Player 2's turn\n\n";
		else 
			cout << "Player 1's turn\n\n";

		// play the move
		playAMove(board, BOARD_SIZE);
	}
	
	// check if there was a winner
	if(checkForWin(board, BOARD_SIZE)) {
		// check who the winner is
		if (playerNumber % 2 == 0)
			winner = "Player 2!";
		else 
			winner = "Player 1!";
		
		// Display the winner
		cout << "Winner: " << winner << endl;
	}
	else
		cout << "Tie!" << endl;

	return 0;
}
