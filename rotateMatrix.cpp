#include<iostream>

using namespace std;

void print(int**a, int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0; j<n ;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}


void rotate(int **a, int startX, int endX)
{
	if(startX >= endX) return;

	for(int i = 0 ;i < endX-startX ; i++)
	{
		int temp = a[endX][i+startX];
		a[endX][i+startX] =  a[endX-i][endX];
		a[endX-i][endX] = a[startX][endX-i];
		a[startX][endX-i] = a[startX+i][startX];
		a[startX+i][startX] = temp;
	}
	rotate(a, startX + 1, endX -1);	
}

void printSpiral(int **a, int startX, int endX)
{
	if(startX == endX) 
	{
		cout<<a[startX][endX]<<" ";
		return;
	}
	if(startX>endX) return;

	for(int i = 0 ; i< endX - startX;i++)
		cout<<a[startX][i+startX]<<" ";

	for(int i = 0 ; i< endX - startX;i++)
		cout<<a[startX+i][endX]<<" ";

	for(int i = 0 ; i< endX - startX;i++)
		cout<<a[endX][endX-i]<< " ";

	for(int i = 0 ; i< endX - startX;i++)
		cout<<a[endX-i][startX]<< " ";
	
	printSpiral(a, startX + 1, endX - 1);
}

int main()
{
	int n = 5;
	int **a;
	a = (int**)malloc(sizeof(int*)*n);	
	for(int i=0;i<n;i++)
		a[i] = (int*)malloc(sizeof(int)*n);	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)	
		a[i][j] = i * n + j + 1;
	
	print(a, n);
	rotate(a,0 , n-1);	
	print(a, n);
	printSpiral(a, 0,n-1);
}
	
