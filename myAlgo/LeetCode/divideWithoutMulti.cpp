#include<iostream>

using namespace std;

int divide(int dividend, int divisor) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int sign = (long)dividend * divisor > 0 ? 1 : -1;
	
	if(dividend>0 && divisor > 0) sign = 1;
	else if(dividend<0 && divisor < 0) sign = 1;
	else sign = -1;
	unsigned denom= divisor >0 ?divisor: -divisor ;
	long current = 1;
	long answer=0;

	unsigned  dividend__unsigned = dividend >0 ? dividend: -dividend ;

	if(denom == 1)
		return dividend__unsigned * sign;	
	
	
	if ( denom > dividend__unsigned) 
		return 0;

	if ( denom == dividend__unsigned)
		return 1;

	while (1) {	
		if(denom<<1 < denom || denom<<1 > dividend__unsigned)
		{
			break;
		}
		denom <<= 1;
		current <<= 1;
	}

	while (current!=0) {
		if ( dividend__unsigned >= denom) {
			dividend__unsigned -= denom;
			answer |= current;
		}
		current >>= 1;
		denom >>= 1;
	}   
	return answer * sign;

}

int main()
{
	int a,b;
	cin>>a;
	cin>>b;
	cout<<divide(a,b);
}
