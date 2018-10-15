#include<iostream>

using namespace std;


void printDiagonal(int **a, int m, int n)
{
	int row = 0;
	int col = 0;
	int diff = -(n-1);
	while(diff!= m)
	{
		if(row >= m || col >=n)
		{ 
			row = 0;
			col = 0;
			diff++;
			cout<<endl;
		}

		if(row - col == diff)
		{
			cout<<a[row][col]<< " ";
			row++;
			col++;
		}
		else if(row - col < diff)
		{
			row++;	
		} 
		else if(row - col > diff)
		{
			col++;
		}
	}
}

int main()
{
	int m = 3, n = 3;
	cin>>m;
	cin>>n;
	int **a;
	a = (int**)malloc(sizeof(int*)*m);
	for(int i=0;i<m;i++)
		a[i] = (int*) malloc(sizeof(int)*n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j] = i * n + j + 1;
		}
	}

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
//			cout<<a[i][j]<<" ";
		}
//		cout<<endl;
	}


	printDiagonal(a, m, n);

}
