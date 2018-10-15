#include<iostream>

using namespace std;
int myPow(int x,int y)
{
	if(y==1)
		return x;
	if(y==0)
		return 1;
	int root = myPow(x,y/2);
	if(y%2==0)
		return root * root;
	else 
		return x * root * root;
}

int main()
{
	int x,pow;
	cin>>x;
	cin>>pow;
	cout<<myPow(x,pow)<<endl;
}
