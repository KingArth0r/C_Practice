#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

static const int INVALID_INPUT_LIMIT = 10;

void printBoard(char state[]) {
	for (int i = 0; i < 6; i++) {
		printf("- ");
	}
	printf("\n");
	for (int i = 0; i < 9; i += 3) {
		printf("| %c | %c | %c |\n",
			       	state[i], state[i + 1], state[i + 2]);
		for (int j = 0; j < 6; j++) {
			printf("- ");
		}
		printf("\n");
	}
}

void printWelcome() {
	printf("WELCOME TO TIC-TAC-TOE\n");
	printf("PRESS 1 FOR SINGLE PLAYER\n");
	printf("PRESS 2 FOR 2-PLAYER\n");
	printf("PRESS c FOR CONTROLS\n");
}

int convertInputToPosition (char input[]) {
	if (!strcmp("top-left", input)) return 0;
	else if (!strcmp("top-middle", input)) return 1;
	else if (!strcmp("top-right", input)) return 2;
	else if (!strcmp("center-left", input)) return 3;
	else if (!strcmp("center", input)) return 4;
	else if (!strcmp("center-right", input)) return 5;
	else if (!strcmp("bottom-left" , input)) return 6;
	else if (!strcmp("bottom-middle", input)) return 7;
	else if (!strcmp("bottom-right", input)) return 8;
	return -1;
}

bool gameEnd(char state[], char mark) {
	// check rows
	for (int i = 0; i < 9; i += 3) {
		if (mark == state[i] && mark == state[i + 1] && mark == state[i + 2]) return true;
	}

	// check columns
	for (int i = 0; i < 3; ++i) {
		if (mark == state[i] && mark == state[i + 3] && mark == state[i + 6]) return true;
	}

	// check both diagonals
	if (mark == state[0] && mark == state[4] && mark == state[8]) return true;
	if (mark == state[2] && mark == state[4] && mark == state[6]) return true;

	return false;
}

void printControls() {
	printf("\nCONTROLS:\n");
	printf("TO PLACE A PIECE, TYPE ONE OF THE FOLLOWING NAMES: \n\n");
	printf("top-left, top-middle, top-right\n");
	printf("center-left, center, center-right\n");
	printf("bottom-left, bottom, bottom-right\n");
	printf("\nPRESS q AT ANY TIME TO QUIT\n\n");
}

int main(int argc, char *argv[]) {
	char state[9] = {' '};
	char player1Mark = 'q';
	char player2Mark = 'q';

	printWelcome();
 
	int invalidInputLimit = INVALID_INPUT_LIMIT;
	char gamemode = '0';

	while (invalidInputLimit > 0) {
		char input;
		scanf("%c", &input);
		if (input  == 'q') exit(0);
		if (input  == 'c') printControls();

		if (input == '1' || input == '2') {
			gamemode = input;
			break;
		}
		if (invalidInputLimit <= 0) {
			printf("Too many bad inputs! Bye!\n");
			exit(0);
		}
		invalidInputLimit--;
		printf("Choose a gamemode!\n");
	}

	if (gamemode == '1') {
		printf("Choose X or O\n");
	}
	
	if (gamemode == '2') {
		printf("Player 1: Choose X or O\n");
	}

	invalidInputLimit = INVALID_INPUT_LIMIT;
	
	while (invalidInputLimit > 0) {
		scanf("%c", &player1Mark);
		if (player1Mark == 'q' || player1Mark == 'Q') exit(0);
		if (player1Mark == 'x' || player1Mark == 'X') {
			player1Mark = 'X';
			player2Mark = 'O';
			break;
		}
		if (player1Mark == 'o' || player1Mark == 'O') {
			player1Mark = 'O';
			player2Mark = 'X';
			break;
		}
		invalidInputLimit--;
	}
	if (invalidInputLimit <= 0) {
		printf("Too many bad inputs! Bye!\n");
	}

	printBoard(state);

	// true for player1's turn, false for player2 or AI
	bool playerTurn = true;
	int turnLimit = 20;
	
	// game loop 
	while (!gameEnd(state, player1Mark) || !gameEnd(state, player2Mark)) {
		if (playerTurn) printf("Player 1: \n");
		else printf("Player 2: \n");

		int position;
		char move[20];

		scanf("%s", move);
		if (move[0] == 'q') break;

		position = convertInputToPosition(move);

		state[position] = playerTurn ? player1Mark : player2Mark;

		printBoard(state);
		if (gameEnd(state, player1Mark) || gameEnd(state, player2Mark)) {
			printf("GAME END\n");
			break;
		}
		playerTurn = !playerTurn;
		turnLimit++;
	}

	return 0;
}
