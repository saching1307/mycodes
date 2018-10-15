#include<iostream>

using namespace std;

int findSmallestDivisible(int sum, int n)
{
	if( sum > INT_MAX || sum <=0) return INT_MAX;
	if(sum % n == 0) return sum;
	int min0 = findSmallestDivisible(sum * 10 + 0, n);
	int min1 = findSmallestDivisible(sum * 10 + 1, n);
	return min(min0, min1);
}

int main()
{
	int n=100;
	cin>>n;
	cout<<findSmallestDivisible(1,n)<<endl;
}
