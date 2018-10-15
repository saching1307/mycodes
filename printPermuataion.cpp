#include<iostream>

using namespace std;

void printPermutation(char a[], int start, int n)
{
	if(start == n )
	{
		cout<<"permi:: ";
		for(int i=0;i<n+1;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
		return;
	}
	else
	{
		for(int i= start ;i < n+1;i++)
		{
			char temp = a[i];
			a[i] = a[start];
			a[start] = temp;
			printPermutation(a,start+1,n);
			char temp1 = a[i];
			a[i] = a[start];
			a[start] = temp1;
		}
	}
}

int main()
{
	char *a;
	a = (char*)malloc(sizeof(char)*3);
	a[0] = 'a';
	a[1] = 'b';
	a[2] = 'c';

	printPermutation(a,0, 2);
}
