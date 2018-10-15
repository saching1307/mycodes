#include<iostream>

using namespace std;

int LIS(int* input, int n)
{
//Dynamic programming
// T(j) = max ( t(i-k) + 1)

	int temp[n];
	int temp2[n];
	for(int i=0;i<n;i++)
	{
		temp[i] = 1;
		temp2[i] = i;
	}

	for(int i=0;i<n;i++)
	{
		for(int j = 0 ; j < i ;j++)
		{
			if( input[i] > input[j])
			{
				if(temp[i] < temp[j] + 1)
				{
				 	temp[i] = temp[j] + 1;
					temp2[i] = j;
				}
			}
		}
	}
	
	int maxIndex = 1;
	int max = INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(max < temp[i])
		{
			max = temp[i];
			maxIndex = i;
		}
	}
	cout<<maxIndex<<endl;
	
	for(int i=0; i<max;i++)
	{
		cout<<input[maxIndex]<<" ";
		maxIndex = temp2[maxIndex];		
	}
	cout<<endl;

	return max;
}

int main()
{
	int input[16] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	int n = 16;
	cout<<LIS(input,16)<<endl;
}
