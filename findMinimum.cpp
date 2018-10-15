#include<iostream>

using namespace std;

int main()
{
	int a[] =  {3, 4, 5, 6, 7, -3, 0, 1, 2};
	int min = 0;
	int max = 6;
	int mid;
	while(min < max)
	{
		mid = a[(min+max)/2];
		if(mid < a[max])
		{
			max = (min + max )/2 - 1;
		}
		else
		{
			min = (min + max )/2 + 1;	
		}
	}
	cout<<mid<<endl;
}
