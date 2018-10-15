#include<iostream>

using namespace std;

void printBoard(int board[4][4],int N)
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<board[i][j];
			cout<<" ";
		}	
		cout<<endl;
	}
}

bool isSafe(int board[4][4], int col, int row, int N)
{
	int i,j;
	for(int i=0;i<col;i++)
	{
		if(board[row][i])
			return false;
	}
	/* Check upper diagonal on left side */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if (board[i][j])
			return false;
	}

	/* Check lower diagonal on left side */
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
	{
		if (board[i][j])
			return false;
	}

	return true;
}

bool solveNQUtil(int board[4][4], int col, int N)
{
	if(col >= N)
	{
		return true;
	}
	for(int i=0 ; i < N;i++)
	{
		if(isSafe(board,col,i,N))
		{
			board[i][col]=1;
			if(solveNQUtil(board,col+1,N))
				return true;
			board[i][col]=0;
		}
	}
	return false;
}

bool solveNQ()
{
	int N = 4;
	int board[4][4] = { {0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	if ( solveNQUtil(board,0,4) == false )
	{
		printf("Solution does not exist");
		return false;
	}

	printBoard(board,4);
	return true;
}

// driver program to test above function
int main()
{
	solveNQ();
	return 0;
}	

