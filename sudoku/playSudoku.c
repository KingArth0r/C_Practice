#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static const int TOTAL_BOARD_SIZE = 27;
static const int CENTER = 1;
static const int MULTIPLIER = 3;

// OUTLINE:
//
// Read random board and its solution from file sudoku_puzzles.txt
// The state of the game is represented by a 9 x 9 array of integers
// The board that is printed recorded by a 27 x 27 array of integers (could be optimized with chars)
// Read input from player and print board after each input
// Player can be in a "note mode" where inputs are put to the board, but do not change the state,
// Player can adjust various settings:
// 	- Number of mistakes allowed
// 	- Immediate feedback
// 	- Difficulty level of puzzles
// Player places a piece by inputting 3 numbers on the same line: row column number 

// input is the 27 x 27 board of numbers and its subnumbers
void printBoard(int board[TOTAL_BOARD_SIZE][TOTAL_BOARD_SIZE]) {
	// print top boarder, the + 9 is to account for the | between squares
	printf("/ ");
	for (int i = 0; i < TOTAL_BOARD_SIZE + 9; i++) {
		printf("-/");
	}
	printf("\\\n");

	for (int i = 0; i < TOTAL_BOARD_SIZE; i++) {
		// print extra separating line
		if (i > 0 && i % 3 == 0) {
			printf("| ");
			if (i > 0 && i % 9 == 0) {
				for (int j = 0; j < TOTAL_BOARD_SIZE + 9; j++) {
					printf("//");
				}
			}
			else {
				for (int j = 0; j < TOTAL_BOARD_SIZE + 9; j++) {
					printf("- ");
				}
			}
			printf("\\\n");
		}
		printf("| ");

		for (int j = 0; j < TOTAL_BOARD_SIZE; j++) {
			if (j > 0 && j < TOTAL_BOARD_SIZE - 1 && j % 3 == 0) printf("| ");
			if (board[i][j] == 0) printf("  ");
			else printf("%d ", board[i][j]);
		}
		printf("|\n");
	}	

	printf("\\ ");
	for (int i = 0; i < TOTAL_BOARD_SIZE + 9; i++) {
		printf("- ");
	}
	printf("/\n");

}

int main() {
	int board[TOTAL_BOARD_SIZE][TOTAL_BOARD_SIZE];
	for (int i = 0; i < TOTAL_BOARD_SIZE; i++) {
		for (int j = 0; j < TOTAL_BOARD_SIZE; j++) {
			board[i][j] = 0;
		}
	}
	
	board[4 * MULTIPLIER + CENTER][0 * MULTIPLIER + CENTER] = 1;	
	printBoard(board);
	return 0;
}
