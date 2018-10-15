#include<iostream>

using namespace std;

void print(int* a, int n)
{
        for(int i=0;i<n;i++) cout<<a[i]<< " ";
        cout<<endl;
}

void intersection(int* a, int* b, int aCount, int bCount)
{
	int i=0;
	int j=0;
	while(i < aCount && j < bCount)
	{
		if(a[i] == b[j])
		{
			cout<<a[i]<<" ";
			i++;
			j++;
		}
		else if(a[i] > b[j])
		{
			j++;
		}
		else
		{
			i++;
		}
	}
	cout<<endl;
}

void unionOfArray(int*a, int *b, int aCount, int bCount)
{
	int i=0;
	int j=0;
	while(i < aCount && j < bCount)
	{
		if(a[i] == b[j])
		{
			cout<<b[j]<<" ";
			i++;
			j++;
		}
		else if(a[i] > b[j])
		{
			cout<<b[j]<<" ";
			j++;
		}
		else
		{
			cout<<a[i]<<" ";
			i++;
		}
	}
	while(i < aCount)
	{
		cout<<a[i]<<" ";
		i++;
	}
	while( j < bCount)
	{
		cout<<b[j]<<" ";
		j++;
	}

	cout<<endl;
}

int main()
{
	int aCount = 5;
	int bCount = 10;
	int a[aCount],b[bCount];
	int common =   1;

	for(int i=0;i<common;i++)
	{
		int randN = rand()%10 - 10;
		a[i] = randN;
		b[i] = randN;
	}
	for(int i=common;i<aCount;i++)
	{
		a[i] = i + 4;
	}	
	
	for(int i=common;i<bCount;i++)
	{
		b[i] = i + 6;
	}	
	print(a, aCount);
	print(b, bCount);
	intersection(a,b,aCount,bCount);
	unionOfArray(a,b,aCount,bCount);
}
