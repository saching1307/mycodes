#include<iostream>

using namespace std;

int absHelper(int a, int b, int c)
{
	int diff1 = abs(a-b);
	int diff2 = abs(b-c);
	int diff3 = abs(c-a);
	if(diff1 < diff2)
	{
		return diff2 > diff3 ? diff2 : diff3;
	}
	else
	{
		return diff1 > diff3 ? diff1 : diff3;
	}
}

int diffInAbsMinimum(int *a, int *b, int *c, int n)
{
	int x,y,z;
	x = y = z = 0;
	int min = INT_MAX;
	while(1)
	{
		int maxDistance = absHelper(a[x],b[y],c[z]);
		if(maxDistance < min)	
		{
			min = maxDistance;
		}
		
		bool isXValid = x < n;	
		bool isYValid = y < n;	
		bool isZValid = z < n;	
		
		if(isXValid && (isZValid == false || (isZValid && c[z] >= a[x])) && 
			(isYValid == false || (isYValid && b[y] >= a[x])))
		{
			x++;
		}
		
		else if(isYValid && (isZValid == false || (isZValid && c[z] >= b[y])) && 
			(isXValid == false || (isXValid && b[y] <= a[x])))
		{
			y++;
		}
			
		else if(isZValid && (isXValid == false || (isXValid && c[z] <= a[x])) && 
			(isYValid == false || (isYValid && b[y] >= c[z])))
		{
			z++;
		}
		
		if(isXValid== false && isYValid == false && isZValid == false)
			return min;
		
		cout<<x<<" "<<y<< " "<<z<<" "<<min<<endl;	
	}
}

int main()
{
	int a[5] = {1,2,23,24,25};
	int b[5] = {-11,12,13,14,25};
	int c[5] = {-30,-32,25,34,35};
	cout<<diffInAbsMinimum(a,b,c,5)<<endl;
}
