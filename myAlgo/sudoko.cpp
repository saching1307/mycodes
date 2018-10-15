#include<iostream>

using namespace std;

void printSolution(int sudoko[9][9])
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout<<sudoko[i][j]<< " ";
		}
		cout<<endl;
	}
}

bool isSafe(int sudoko[9][9], int row , int col, int number)
{
	for(int i=0;i<9;i++)
	{
		if(sudoko[row][i]==number)
			return false;
		if(sudoko[i][col]==number)
			return false;
	}
	
	int rowPosition = row%3;
	int columnPosition = col%3;

	for(int i=row/3 * 3; i< row/3 * 3 + 3 ; i++)
	{
		for(int j=col/3 * 3; j< col/3 * 3 + 3 ; j++)
		{
			if(sudoko[i][j]==number)
			{
				return false;
			}
		}
	}
	
	return true;
}

bool solveSudoko(int sudoko[9][9])
{
	int unassignedLocationFound = false;
	int i,j;
	for(i=0;i<9;i++)	
	{
		for(j=0;j<9;j++)
		{
			if(sudoko[i][j]!=0)
				continue;
			else
			{
				unassignedLocationFound = true;
				break;
			}
		}
		if(unassignedLocationFound) break;
	}
	for(int k=1;k<10;k++)
	{
		if(isSafe(sudoko,i,j,k))
		{
			sudoko[i][j]=k;
			if(solveSudoko(sudoko))
			{
				return true;
			}
			sudoko[i][j]=0;
		}
	}

	return !unassignedLocationFound;
}


int main()
{
	int sudoko[9][9] =
	{
	{0,0,6,5,0,8,4,0,0},
	{5,2,0,0,0,0,0,0,0},
	{0,8,7,0,0,0,0,3,1},
	{0,0,3,0,1,0,0,8,0},
	{9,0,0,8,6,3,0,0,5},
	{0,5,0,0,9,0,6,0,0},
	{1,3,0,0,0,0,2,5,0},
	{0,0,0,0,0,0,0,7,4},
	{0,0,5,2,0,6,3,0,0},
	};
	solveSudoko(sudoko);
	printSolution(sudoko);
}
