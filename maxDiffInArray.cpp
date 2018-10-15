#include<iostream>

using namespace std;

int longestDiff(int *a, int n)
{
    int max = INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j = i + 1; j < n ; j++)
        {
            int diff = a[j] - a[i];
            if(diff > max)
            {
                max = diff;
            }
        }   
    }
    return max;
}

int main()
{
	int n = 7;
	int a[n];
	for(int i=0;i<n;i++) a[i] = i+1;
	cout<<longestDiff(a, n)<<endl;
}
