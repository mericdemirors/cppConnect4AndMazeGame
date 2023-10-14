#include "fonksiyonlar.h"
#include <iostream> 
#include <stdio.h>  
using namespace std;  

void print_board(float**, int, int);
bool put(float**, char, int);
void end(float** board, int p);

int main()
{
	float** board = create_matrix(6,7);
	for(int i=0; i<6; i++)
		for(int j=0; j<7; j++)
			board[i][j] = 0;
	
	print_board(board, 6,7);
	
	int player = -1;
	char input;

	while (true)
	{
		if (player == -1)
		{
			// Set terminal to raw mode, Wait for single character, Reset terminal to normal "cooked" mode 
			system("stty raw");  input = getchar();  system("stty cooked");
			if (put(board, input, player))
			{
				player = 1;
				end(board, -1);
			}
			print_board(board, 6, 7);
		}
		
		if (player == 1)
		{
			// Set terminal to raw mode, Wait for single character, Reset terminal to normal "cooked" mode 
			system("stty raw");  input = getchar();  system("stty cooked");
			if (put(board, input, player))
			{
				player = -1;
				end(board, 1);
			}
			print_board(board, 6, 7);
		}
	}

	return 0;
}

void print_board(float** board, int r, int c)
{
	cout << "\n╔";
	for(int i=0; i<2*c-1; i++) cout << "═";
	cout << "╗\n";
	
	for(int i=0; i<r; i++)
	{
		cout << "║";
		for(int j=0; j<c; j++)
			if(j!=c-1)
			{
				if (board[i][j] == -1) cout << "○ ";
				else if (board[i][j] == 1) cout << "● ";
				else cout << "_ ";		
			}
			else
			{
				if (board[i][j] == -1) cout << "○";
				else if (board[i][j] == 1) cout << "●";
				else cout << "_";
			}
		cout << "║\n";
	}
	
	cout << "╠";
	for(int i=0; i<2*c-1; i++) cout << "═";
	cout << "╣\n║1║2║3║4║5║6║7║\n";
	cout << "╚";
	for(int i=0; i<2*c-1; i++) if(i%2==0) cout << "═"; else cout << "╩";
	cout << "╝\n\n";
}

bool put(float** board, char c, int p)
{
	int col = int(c)-49;

	if (c=='q') exit(0);
	if (board[0][col] != 0)
	{
		cout << "cannot place there!\n";
		return false;
	}

	int row;
	for(row=5; row>=0; row--)
		if (board[row][col] == 0) break;
	
	board[row][col] = p;
	return true;
}

void end(float** board, int p)
{
	string shapes[3] = {"○", "", "●"};
	for(int j=0; j<6; j++)
		for(int i=0; i<4; i++)
			if ((board[j][i] + board[j][i+1] + board[j][i+2] + board[j][i+3]) == 4*p)
			{
				print_board(board, 6, 7);
				cout << shapes[p+1] << " won!\n";
				exit(0);
			}
			
	for(int j=0; j<3; j++)
		for(int i=0; i<7; i++)
			if ((board[j][i] + board[j+1][i] + board[j+2][i] + board[j+3][i]) == 4*p)
			{
				print_board(board, 6, 7);
				cout << shapes[p+1] << " won!\n";
				exit(0);
			}
			
	for(int j=0; j<3; j++)
		for(int i=0; i<4; i++)
			if ((board[j][i] + board[j+1][i+1] + board[j+2][i+2] + board[j+3][i+3]) == 4*p)
			{
				print_board(board, 6, 7);
				cout << shapes[p+1] << " won!\n";
				exit(0);
			}
			
	for(int j=0; j<3; j++)
		for(int i=6; i>=3; i--)
			if ((board[j][i] + board[j+1][i-1] + board[j+2][i-2] + board[j+3][i-3]) == 4*p)
			{
				print_board(board, 6, 7);
				cout << shapes[p+1] << " won!\n";
				exit(0);
			}
}








