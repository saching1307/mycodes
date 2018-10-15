#include<iostream>

using namespace std;

int noOfBinary(int n)
{
	int totalOnes = 0;
	while(n>0)
	{
		n = n & (n-1);
		totalOnes++;
	}
	return totalOnes;
}

int main()
{
	int n;
	cin>>n;
	cout<<noOfBinary(n);
}
