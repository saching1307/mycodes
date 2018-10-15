#include<iostream>

using namespace std;

static int MAX_CAPACITY  = 24;

bool isBreaking(int a)
{
	if(a < MAX_CAPACITY)
		return true;
	return false;
}

int searchInRange(int low, int high)
{
	if(low == 0) return high;
	if(low >= high) return low;
	if(isBreaking((low + high)/2))
	{
		return searchInRange((low + high)/2 + 1, high);
	}
	else 
	{
		return searchInRange(low, (low + high)/2);
	}
	return -1;
}

int maxHammerCapacity()
{
	int i = 1;
	while(isBreaking(i))	
	{
		i *= 2;
	}
	return searchInRange(i/2,i);
}

int main()
{
	cout<<maxHammerCapacity();
}
