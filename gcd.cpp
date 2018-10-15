#include<iostream>

using namespace std;

int gcd(int m, int n)
{
	if(n==0) return m;
	if(m%n == 0) return n;
	else	
		return gcd(n, m%n);
}

int lcm(int m, int n)
{
	int gcd_ = gcd(m, n);
	return m*n/gcd_;
}

int main()
{
	cout<<gcd(16, 0)<<endl;
	cout<<lcm(114, 18)<<endl;
}
