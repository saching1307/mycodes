#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int output = 0;
	while(n!=0)
	{
		output = output<<1;
		output |= n & 1;
		n = n>>1;
	}
	cout<<output;
}
