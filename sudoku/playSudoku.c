#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static const int TOTAL_BOARD_SIZE = 27;
static const int SIZE = 9;
static const int CENTER = 1;
static const int MULTIPLIER = 3;
static const char *DELIM = ",";

// OUTLINE:
//
// Read random board and its solution from file puzzles directory
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
	printf("/|");
	for (int i = 0; i < TOTAL_BOARD_SIZE + 8; i++) {
		printf("//");
	}
	printf("|\\\n");

	for (int i = 0; i < TOTAL_BOARD_SIZE; i++) {
		// print extra separating line
		if (i > 0 && i % 3 == 0) {
			printf("||");
			if (i > 0 && i % 9 == 0) {
				for (int j = 0; j < TOTAL_BOARD_SIZE + 8; j++) {
					printf("//");
				}
			}
			else {
				for (int j = 0; j < TOTAL_BOARD_SIZE + 8; j++) {
					printf("- ");
				}
			}
			printf("||\n");
		}
		printf("||");

		for (int j = 0; j < TOTAL_BOARD_SIZE; j++) {
			if (j > 0 && j < TOTAL_BOARD_SIZE - 1 && j % 3 == 0) {
				if (j % 9 == 0) printf("||");       
				else printf("| ");
			}
			if (board[i][j] == 0) printf("  ");
			else printf("%d ", board[i][j]);
		}
		printf("||\n");
	}	

	printf("\\|");
	for (int i = 0; i < TOTAL_BOARD_SIZE + 8; i++) {
		printf("//");
	}
	printf("|/\n");

}

void printMemError(int lineNum) {
	printf("Cannot allocate memory in line %d\n", lineNum);
}

// ask Kyle about asprintf
int** initBoard(int boardNum, bool isSolution) {
	int** state = malloc(SIZE * sizeof(int*));
	if (state == NULL) {
		printMemError(__LINE__);
		exit(1);
	}

	for (int i = 0; i < SIZE; i++) {
		state[i] = calloc(SIZE, sizeof(int));
		if (state == NULL) {
			printMemError(__LINE__);
			exit(1);
		}
	}

	//char *filename;
	//if (isSolution) {
	//	int temp = asprintf(&filename,  "board%dsolution.txt", boardNum);
	//	if (temp == -1) {
	//		printMemError(__LINE__);
	//		exit(1);
	//	}
	//} else {
	//	int temp = asprintf(&filename, "board%d.txt", boardNum);
	//	if (temp == -1) {
	//		printMemError(__LINE__);
	//		exit(1);
	//	}
	//}	

	FILE *fp = fopen("board1solution.txt", "r");
	if (fp == NULL) {
		printf("Can't open file!\n");
		exit(1);
	}
	char *line = NULL;
	size_t len = 0;
	char *token = NULL;
	for (int i = 0; i < SIZE; i++) {
		// read line
		if (getline(&line, &len, fp) == -1) {
			printf("Error while reading line %i of the board.\n", i);
			// free before exiting
			for (int i = 0; i < SIZE; i++) {
				free(state[i]);
			}
			free(state);
			free(line);
			//free(filename);

			exit(1);
		}

		token = strtok(line, DELIM);
		for (int j = 0; j < SIZE; j++) {
		       state[i][j] = atoi(token);
		       token = strtok(NULL, DELIM);
		}
	}

	free(line);
	line = NULL;
	// free(filename);
	// filename = NULL;
	return state;	
}	

int main() {
	int **state = initBoard(1, false);

	int board[TOTAL_BOARD_SIZE][TOTAL_BOARD_SIZE];
	for (int i = 0; i < TOTAL_BOARD_SIZE; i++) {
		for (int j = 0; j < TOTAL_BOARD_SIZE; j++) {
			board[i][j] = 0;
		}
	}
	

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			board[MULTIPLIER * i + CENTER][MULTIPLIER * j + CENTER] = state[i][j];
		}
	}	
	printBoard(board);


	for (int i = 0; i < SIZE; i++) {
		free(state[i]);
	}
	return 0;
}
