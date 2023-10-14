#include "fonksiyonlar.h"
#include <iostream> 
#include <stdio.h>  
using namespace std;  

void print_maze(float**, int, int);
int* move(float**, int, int, int, int, char);

int main()
{
	cout << "Enter the maze size:";
	int r, c, x=0, y=0;
	cin >> r >> c;
	float** maze = create_matrix(r,c);
	
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			if (maze[i][j] < 0) maze[i][j] = -1;
			else maze[i][j] = 1;

	maze[0][0] = 0;
	print_maze(maze, r, c);

	cin.ignore();
	while (true)
	{
		// Set terminal to raw mode 
		system("stty raw"); 
		
		// Wait for single character 
		char input = getchar(); 
		
		// Reset terminal to normal "cooked" mode 
		system("stty cooked");
		
		int* x_y = move(maze,r,c,x,y,input);
		if (x_y == NULL) continue;
		
		x=x_y[0];
		y=x_y[1];
		

		print_maze(maze, r, c);

		if (x==r-1 && y==c-1)
		{
			cout << "ESCAPED!\n";
			exit(0);
		}	
	}



	return 0;
}

void print_maze(float** maze, int r, int c)
{
	cout << "\n╔";
	for(int i=0; i<c; i++) cout << "═";
	cout << "╗\n";
	
	for(int i=0; i<r; i++)
	{
		cout << "║";
		for(int j=0; j<c; j++)
			if (maze[i][j] == -1) cout << "█";
			else if (maze[i][j] == 1) cout << " ";
			else cout << "+";
		cout << "║\n";
	}
	
	cout << "╚";
	for(int i=0; i<c; i++) cout << "═";
	cout << "╝\n\n";

}






int* move(float** maze, int r, int c, int x, int y, char i)
{
	int old_x = x, old_y=y;
	
	if (i=='w') x=x-1;
	else if (i=='s') x=x+1;
	else if(i=='a') y=y-1;
	else if(i=='d') y=y+1;
	else if(i=='q') exit(0);
	else
	{
		cout << "input w,a,s,d.\n";
		return NULL;
	}


	if ((x<0 || x>=r) || (y<0 || y>=c) || (maze[x][y] == -1))
	{
		cout << "can't move there\n";
		return NULL;
	}
	else
	{
		maze[old_x][old_y] = 1;
		maze[x][y] = 0;	
		
		int* x_and_y = (int*)malloc(2*sizeof(int));
		x_and_y[0] = x;
		x_and_y[1] = y;
		return x_and_y;
	}	
	
	
}









