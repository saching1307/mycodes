#include<iostream>


void printLCS(int *a, int n)
{
	int dp[n], c[n];
	for(int i=0;i<n;i++)
	{
			dp[i] = i;
			c[i] = 100000;
	}

	int maxAtIndex = 0;	
	c[0] = a[0];
	dp[0] = 1;
	for(int i=1;i<n;i++)
	{
		if(a[i]<c[0])
		{
			c[0] = a[i];
			dp[i]=1;
		}
		if(a[i] > c[maxAtIndex])
		{
			dp[i] = maxAtIndex+1;	
			c[maxAtIndex +1] = a[i];
			maxAtIndex++;
		}
		else
		{
			int k;
			int left =0;
			int right = maxAtIndex;
			while(left < right)
			{
				int mid = (left + right )/ 2;
				if(a[i] > a[mid])
				{
					left = mid;
				}
				else if(a[i] < a[mid])
				{
					right = mid;
				}
			}
			if(abs(right - left) == 1)
			{
				k =  mid + 1;
				break;		
			}
		}
		c[k] = a[i];
		dp[i] = k;
	}
}

int main()
{
	int n;
	cin>>n;
	int *a;
	a =(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	printLCS(a,n);
}
