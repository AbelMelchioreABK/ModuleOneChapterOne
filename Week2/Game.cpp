#include "Game.h"
#include <iostream>
#include <string>
#include <stdlib.h>

void Game::resetBoard() {
	// might be faster to just make a new board matrix?
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = 0;
		}
	}
}

bool Game::isValidSelection(int x, int y) {
	if (x < 0 || x > 2 || y < 0 || y > 2) {
		return false;
	}

	if (board[x][y] != 0) {
		return false;
	}

	return true;
}

bool Game::checkWin(int player)
{
	// check rows
	for (int i = 0; i < 3; i++) {
		bool completeRow = true;
		for (int j = 0; j < 3; j++) {
			if (board[i][j] != player) {
				completeRow = false;
				break;
			}
		}
		if (completeRow) {
			return true;
		}
	}

	// check columns
	for (int i = 0; i < 3; i++) {
		bool completeCol = true;
		for (int j = 0; j < 3; j++) {
			if (board[j][i] != player) {
				completeCol = false;
				break;
			}
		}
		if (completeCol) {
			return true;
		}
	}

	// check 2 dignals
	// if this fails it can't be dignals
	if (board[1][1] == player) {
		// top left first check
		if (board[0][0] == player && board[2][2] == player) {
			return true;
		}
		// top right last check
		if (board[0][2] == player && board[2][0] == player) {
			return true;
		}
	}

	return false;
}

void Game::showBoard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << board[i][j];
			if (j != 2) {
				std::cout << "|";
			}
		}
		std::cout << std::endl;
		if (i != 2) {
			std::cout << "-----" << std::endl;
		}

	}
}

void Game::startGameLoop() {
	std::cout << "Welcome to tic tac toe. You're gonna be player 1 :D. Press the enter key to continue to the game." << std::endl;
	std::cin.get();
	std::cin.ignore(1000, '\n');

	std::string keepPlaying = "";

	do {
		resetBoard();
		playGame();
		showBoard();
		std::cout << "Type y if you'd like to play another game." << std::endl;
		std::cin >> keepPlaying;
		std::cin.ignore(1000, '\n');
	} while (!keepPlaying.compare("y"));
}

void Game::playGame() {

	int turns = 0;

	// player goes first then we 
	while(turns <= 9) {
		showBoard();
		playTurn();
		if (checkWin(1)) {
			std::cout << "YOU WON. LETS GOOOOO. :D" << std::endl;
			return;
		}

		bool npcTurnDone = false;

		do {
			int x = std::rand() % 3;
			int y = std::rand() % 3;
			npcTurnDone = isValidSelection(x, y);
			if (npcTurnDone) {
				board[x][y] = 2;
			}
		} while (!npcTurnDone);
		if (checkWin(2)) {
			std::cout << "Yikes. You lost to pure RNG... D:" << std::endl;
			return;
		}


		turns += 1;
	};

	std::cout << "Draw :|" << std::endl;
}

void Game::playTurn() {
	
	bool turnComplete = true;

	do {
		turnComplete = true;
		std::cout << "Enter two number seperated by a space to claim the square" << std::endl;
		std::string input;
		std::getline(std::cin, input);
		int spaceLocation = input.find(" ");
		if (spaceLocation == 1 && input.size() == 3) {
			char xChar = input.at(0);
			char yChar = input.at(2);
			if (isdigit(xChar) && isdigit(yChar)) {
				int x = xChar - '0';
				int y = yChar - '0';
				if (isValidSelection(x, y)) {
					board[x][y] = 1;
				}
				else {
					turnComplete = false;
				}
			}
			else {
				turnComplete = false;
			}
		}
		else {
			turnComplete = false;
		}
		

	} while (!turnComplete);

}

void Game::askForGuess() {
	std::cout << "Please enter two numbers seperated by a space between (0-2)" << std::endl;
}
