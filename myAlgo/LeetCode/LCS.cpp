#include<iostream>

using namespace std;

int lcs(int *a,int n)
{
	int b[n];
	for(int i=0;i<n;i++)
	{
		b[i]=1;
	}
	int max; 
	for(int i=0;i<n;i++)
	{
		max = 0;
		for(int j=0;j<i;j++)
		{
			if(a[i] > a[j])
			{
				if(max < b[j])
					max = b[j];
			}
		} 
		b[i] = max + 1;
	}

	max = 0;

	for(int i=0;i<n;i++)
	{
		if(max < b[i])
			max = b[i];
	}            
	return max;
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
	cout<<lcs(a,n)<<endl;
}

