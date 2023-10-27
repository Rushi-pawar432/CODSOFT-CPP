
#include <iostream>
using namespace std;

void DrawBoard();		
void GetInput();		
int CheckWinner();		


const int FREE = 0;		
const int FALSE = 0;
const int X = 1;		
const int O = 2;		
const int DRAW = -1;	


char board[9] = { '1','2','3','4','5','6','7','8','9' };	
int player = X;		


int main()
{
	int winner = FALSE;	


	while (!winner)
	{
		DrawBoard();
		GetInput();
		winner = CheckWinner();

		if (player != O) player = O; else player = X;	
	}
	DrawBoard();
	if (winner == DRAW) 
	cout << "The game was a draw!\n";
	else 
		cout << "Congratulations Player " << winner << "!\nYou win!\n";

	
cin.ignore();
	cin.get();
}


void DrawBoard()
{
	system("CLS");		// If you can't compile, remove this (not compatible with all systems)
	std::cout
		<< "Tic Tac Toe v1.1 : THANK YOU REDDIT! <3\n"
		<< " " << board[0] << " | " << board[1] << " | " << board[2] << " \n"
		<< "-----------\n"
		<< " " << board[3] << " | " << board[4] << " | " << board[5] << " \n"
		<< "-----------\n"
		<< " " << board[6] << " | " << board[7] << " | " << board[8] << " \n";
}

void GetInput()
{
	int position_input;

	
	while (true)
	{
		cout << "Player " << player << "\n" << "Enter a position (1-9):\n";
		cin >> position_input;
		position_input--;			
		if (position_input < 0 || position_input > 8 || board[position_input] == 'X' || board[position_input] == 'O')
		{
			system("CLS");		
			DrawBoard();			
			std::cout << "INVALID POSITION, TRY AGAIN...\n";
			continue;
		}
		break;
	}

	if (player != X) board[position_input] = 'O';
	else board[position_input] = 'X';
}

int CheckWinner()
{
	if (board[0] == board[1] && board[1] == board[2]) return player;
	else if (board[3] == board[4] && board[4] == board[5]) return player;
	else if (board[6] == board[7] && board[7] == board[8]) return player;

	else if (board[0] == board[3] && board[3] == board[6]) return player;
	else if (board[1] == board[4] && board[4] == board[7]) return player;
	else if (board[2] == board[5] && board[5] == board[8]) return player;

	else if (board[0] == board[4] && board[4] == board[8]) return player;
	else if (board[2] == board[4] && board[4] == board[6]) return player;

	else return FALSE;
}
