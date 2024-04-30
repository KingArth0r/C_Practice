#define _GNU_SOURCE
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
void printBoard(int **board, int **state, bool isNoteMode) {
	// print top boarder, the + 9 is to account for the | between squares
	printf("\n");
	printf("/|");
	if (isNoteMode) {
		printf("/");
		for (int i = 0; i < TOTAL_BOARD_SIZE / 2 + 1; i++) printf("//");
		printf(" NOTE MODE ");
		for (int i = 0; i < TOTAL_BOARD_SIZE / 2 + 2; i++) printf("//");
	}
	else for (int i = 0; i < TOTAL_BOARD_SIZE + 8; i++) printf("//");
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
			else if (board[i][j] == state[(i - CENTER) / MULTIPLIER][(j - CENTER) / MULTIPLIER]) {
				printf("\033[0;31m");
				printf("%d ", board[i][j]);
				printf("\033[0m");		
			}		
			else {
				if (!isNoteMode) printf("%d ", board[i][j]);
				else {
					printf("\033[0;34m");
					printf("%d ", board[i][j]);
					printf("\033[0m");
				}
			}
		}
		printf("||\n");
	}	

	printf("\\|");
	if (isNoteMode) {
		printf("/");
		for (int i = 0; i < TOTAL_BOARD_SIZE / 2 + 1; i++) printf("//");
		printf(" NOTE MODE ");
		for (int i = 0; i < TOTAL_BOARD_SIZE / 2 + 2; i++) printf("//");
	}
	else for (int i = 0; i < TOTAL_BOARD_SIZE + 8; i++) printf("//");
	printf("|/\n");

}

void printWelcome() {
	printf("\n=====================WELCOME TO SUDOKU!=====================\n\n");
	printf("Press P to play\n");
	printf("Press C for controls\n");
	printf("Press O for options\n\n");
	printf("Press Q to exit\n");
}

void printControls() {
	
}

void printOptions() {

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

	char *filename;
	if (isSolution) {
		int temp = asprintf(&filename,  "board%dsolution.txt", boardNum);
		if (temp == -1) {
			printMemError(__LINE__);
			exit(1);
		}
	} else {
		int temp = asprintf(&filename, "board%d.txt", boardNum);
		if (temp == -1) {
			printMemError(__LINE__);
			exit(1);
		}
	}	

	FILE *fp = fopen(filename, "r");
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
			fclose(fp);
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
	fclose(fp);
	// free(filename);
	// filename = NULL;
	return state;	
}

int* convertMoveToPosition(int *input, bool isNoteMode) {
	// int array which stores values (row, col, val) and converts them to their position on the board
	int *position = malloc(3 * sizeof(int));
	if (!isNoteMode) {
		position[0] = MULTIPLIER * (input[0] - 1) + CENTER;
		position[1] = MULTIPLIER * (input[1] - 1) + CENTER;
		position[2] = input[2];
	} else {
		position[0] = MULTIPLIER * (input[0] - 1) + (input[2] - 1) / 3;
		position[1] = MULTIPLIER * (input[1] - 1) + (input[2] - 1) % 3;
		position[2] = input[2];
	}

	return position;
}

bool isFinished(int **state, int **solution) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (state[i][j] != solution[i][j]) return false;
		}
	}
	return true;
}

bool isValid(int **state) {
	bool seen[SIZE];
	for (int i = 0; i < SIZE; i++) {
		seen[i] = false;
	}

	// check rows
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (state[i][j] > 0) {
				if (seen[state[i][j] - 1]) return false;
				else seen[state[i][j] - 1] = true;
			}
		
		}
		memset(seen, 0, sizeof(seen));
	}

	// check colmns
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (state[i][j] > 0) {
				if (seen[state[i][j] - 1]) return false;
				else seen[state[i][j] - 1] = true;
			}
		}
		memset(seen, 0, sizeof(seen));
	}

	// check sub-boxes
	for (int n = 0; n < SIZE; n += 3) {
		for (int m = 0; m < SIZE; m += 3) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (state[i][j] > 0) {
						if (seen[state[n + i][m + j] - 1]) return false;
						else seen[state[n + i][n + j] - 1] = true;
					}
				}
			}
			memset(seen, 0, sizeof(seen));
		}
	}
	return true;
}

void playGame(int boardNum, int maxNumMistakes) {
	int **state = initBoard(boardNum, false);
	int **solution = initBoard(boardNum, true);
	int numMistakes = 0;
	bool noteMode = false;

	int **board = malloc(TOTAL_BOARD_SIZE * sizeof(int*));
	for (int i = 0; i < TOTAL_BOARD_SIZE; i++) {
		board[i] = calloc(TOTAL_BOARD_SIZE, sizeof(int));
	}
	
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			board[MULTIPLIER * i + CENTER][MULTIPLIER * j + CENTER] = state[i][j];
		}
	}
	
	while (!isFinished(state, solution)) {

		printBoard(board, state, noteMode);

		int *move = malloc(3 * sizeof(int));
		char input;
		bool clearTile = false;
		
		printf("Mistkaes: %d/%d", numMistakes, maxNumMistakes);

		scanf(" %c", &input);
		if (input == 'q' || input == 'Q') break;
		if (input == 'n' || input == 'N') {
			noteMode = !noteMode;
			printBoard(board, state, noteMode);
		}
		
		printf("Make a move! (row column digit): ");
		scanf("%d %d %d", move, move + 1, move + 2);

		if (move[2] == 0) clearTile = true;

		if (move[0] <= 0 || move[0] > 9 || move[1] <= 0 || move[1] > 9 || move[2] < 0 || move[2] > 9) {
			printf("Please enter a valid input! (row column digit)\n");
			free(move);
			continue;
		}

		if (solution[move[0] - 1][move[1] - 1] == move[2]) {
			state[move[0] - 1][move[1] - 1] = move[2];
		} else {
			printf("Incorrect!\n");
			numMistakes++;
			free(move);
			continue;
		}

		if (numMistakes > maxNumMistakes) {
			printf("You lose!\n");
			break;
		}


		int *position = convertMoveToPosition(move, noteMode);
	
		board[position[0]][position[1]] = position[2];
		printBoard(board, state, noteMode);	

		free(move);
		free(position);
	}

	// free everything
	for (int i = 0; i < SIZE; i++) {
		free(solution[i]);
	}
	free(solution);

	for (int i = 0; i < SIZE; i++) {
		free(state[i]);
	}
	free(state);
	for (int i = 0; i < TOTAL_BOARD_SIZE; i++) {
		free(board[i]);
	}
	free(board);
}

int main() {
	while (true) {
		printWelcome();
		char input;
		scanf("%c", &input);
		if (input == 'q' || input == 'Q') break;
		else if (input == 'p' || input == 'P') playGame(1, 5);
		else if (input == 'c' || input == 'C') printControls();
		else if (input == 'o' || input == 'O') printOptions();
		else printf("Please enter an option!: ");
	}

	return 0;
}
