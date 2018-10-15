#include<iostream>

using namespace std;

int Fib(int a)
{
	if(a - 1 == 0)
		return 0;
	else if(a - 2 == 0)
	{
		return 1;
	}	
	int last = 1;
	int lastSecond = 0;
	a -= 2;
	while( a!=0)
	{
		int temp = last + lastSecond;
		lastSecond = last;
		last = temp;
		a--;
	}
	return last;
}

int main()
{
	for(int i=1; i<11;i++)
	{
		cout<<Fib(i)<< " ";
	}
}
	
