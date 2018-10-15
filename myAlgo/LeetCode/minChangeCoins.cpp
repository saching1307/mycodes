#include<iostream>

using namespace std;

int minimumCoins(int *a,int n,int sum)
{
	int minimumCoin = sum;

	int b[sum+1];
	for(int i=0;i<sum;i++)
	{
		b[i]= i;
	}
	
	b[0] = 0;
	int min;
	for(int i=1;i<=sum;i++)
	{
		min = b[i];
		for(int j=0; j<n ;j++)
		{
			if( i >= a[j] && min > b[i-a[j]]+1)
			{
				min = b[i-a[j]] + 1;
			}
		}
		b[i] = min;
	}
	return b[sum];
}

int main()
{    
	int n;
	cin>>n;
	int *a = (int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
	{   
		cin>>a[i];
	}   
	int sum;
	cin>>sum;
	cout<<minimumCoins(a,n,sum)<<endl;
}

