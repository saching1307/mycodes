#include<iostream>

using namespace std;

void maxSum(int *a)
{
	int n = 9; //sizeof(a)/sizeof(a[0]);
	int maxSumArray[n];
	for(int i=0;i<n;i++)
	{
		maxSumArray[i] = a[i];
	}
	int maxSum = INT_MIN;
	int start, end;
	start = end = 0;
	int sum = 0;
	
	for(int i=0;i<n;i++)
	{
		sum += a[i];
		if(sum < 0)
		{
			sum = 0;
			start = i+1;
		}
		if(sum > maxSum)
		{
			maxSum = sum;
			end = i;
		}
	}

	cout<<start<<" "<<end<< " "<<maxSum<<endl;	

}

int main()
{
	int a[] = {-2,1,-3,4,-1,2,1,-5,4};
	maxSum(a);
}
