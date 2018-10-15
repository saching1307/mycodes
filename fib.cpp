#include<iostream>

using namespace std;

int fib(int n)
{
	int last = 0;
	int lastSecond = 1;
	if(n == 0) return 0;
	if(n==1) return 1;
	int sum;	
	while(n>0)
	{
		sum = last + lastSecond;
		lastSecond = last;	
		last = sum;
		n--;
	}
	return sum;
}

int main()
{
	int n;	
	cin>>n;
	cout<<fib(n-1)<<endl;
}

