#include<iostream>

using namespace std;

void print(int* a, int n)
{
	for(int i=0;i<n;i++) cout<<a[i]<< " ";
	cout<<endl;
}

void moveZeroToEnd(int *a, int start, int end)
{
	while(start < end && a[start]!=0)
	{
		start++;
	}

	while(start < end && a[end]==0)
	{
		end--;
	}
	
	if(start < end)
	{
		int temp = a[end];
		a[end] = a[start];
		a[start] = temp;
		return moveZeroToEnd(a,start+1,end-1);
	}
	return;
}

int main()
{
	int n = 10;
	int m = 4;
	int a[n];
	for( int i = 0; i<n ;i++)
		a[i] = rand()%5;
	for( int i = 0; i<m ;i++)
		a[rand()%n] = 0;
	print(a,n);
	moveZeroToEnd(a,0,n-1);
	print(a,n);
}
