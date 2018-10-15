#include<iostream>
#include<math.h>

using namespace std;

void swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

bool isBinaryOneAtPosition(int n, int i)
{
	return n & (1 << i);
}

void printSet(int *a, int n)
{
	int totalSets = 0;

	while(totalSets < pow(2,n))
	{
		for(int i=0;i<n;i++)
		{
			if(isBinaryOneAtPosition(totalSets,i)==1)
				cout<<a[i]<<" ";
			else 
				cout<<"*"<<" ";
		}
		cout<<endl;
		totalSets++;
	}
}

void printPermutations(int *a, int j,int n)
{
	if(n == j)
	{
		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}

	for(int i=j;i<n;i++)
	{
		swap(a[i],a[j]);
		printPermutations(a,j+1,n);
		swap(a[i],a[j]);
	}
}

int main()
{
	int n = 4;
	int *a;
	a = (int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) 
		a[i] = i+1;

	//printPermutations(a,0,n);
	printSet(a,n);
}
