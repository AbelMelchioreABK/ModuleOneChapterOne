#pragma once
class Game
{
	private:
		int board[3][3] = {
			{0,0,0},
			{0,0,0},
			{0,0,0},
		};

	public:
		void resetBoard();
		bool isValidSelection(int x, int y);
		bool checkWin(int player);
		void showBoard();
		void startGameLoop();
		void askForGuess();
		void playGame();
		void playTurn();

};

