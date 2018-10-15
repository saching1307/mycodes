#include<iostream>
#include<cmath>

using namespace std;
#define ERROR_MARGIN 0.00001

float mySqrt(float i)
{
	if(i == 1)
		return 1;
	else if(i < 0)
		return INT_MIN;
	else if(i > 1) 
	{
		float  low = 0;
		float mid;
		float high = i;
		while(1)
		{
			mid = (low + high)/2.0;
			float diff = abs((mid * mid) - (float)i);
			if(diff < ERROR_MARGIN)
				return mid;
			else if(mid * mid > i - ERROR_MARGIN)
			{
				high = mid;
			}
			else
			{
				low = mid;
			}
		//	cout<<diff<< " "<<i<<endl;
		}
	}
	else if(i < 1)
	{
		float tenth = 1;
		while( i < 1)
		{
			tenth *= 0.1;
			i = i*100;
		}
		return mySqrt(i) * tenth; 
	}
}

int main()
{
	for(int i = 1; i< 10;i++)
	{
		cout<<mySqrt(i)<<" ";
	}
		cout<<mySqrt(0.4)<<" ";
		cout<<mySqrt(0.16)<<" ";
}
