#include<iostream>

using namespace std;


int maximumContigousSum(int *a,int n)
{
	int b[n];
	int maxSum = -200;// INT_MIN;
	int tempSum = 0;
	for(int i=0;i<n;i++)
		b[i] = a[i];

	if(n >= 1)    
		tempSum = b[0];
	for(int i=1;i<n;i++)
	{
		if(b[i]+tempSum > b[i])
		{
			b[i] = b[i] + tempSum;
		}

		if(b[i] + tempSum < 0)
		{
			tempSum = 0;
		}
		else
		{
			tempSum= b[i];
		}
		cout<<tempSum<<endl;  
	} 

	for(int i=0;i<n;i++)
	{
		if(maxSum < b[i])
		{
			maxSum = b[i];
		}
	}

	return maxSum;
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
	cout<<maximumContigousSum(a,n)<<endl;
}
