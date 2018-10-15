#include<iostream>

using namespace std;

int search(int *a, int n, int k)
{
	int low = 0;
	int high = n - 1;
	int mid = -1;
	while(high >= low)
	{
		mid = (high+low)/2;
		if(a[mid] == k)
		{
			return mid;
		}
		else
		{
			if(a[low] < a[mid])
			{
				if(a[low] < k && a[mid] > k)
				{
					high = mid - 1;
				}
				else
					low = mid + 1;
			}
			else
			{
				if(a[high] > k && a[mid] < k)
				{
					low = mid + 1;
				}
				else
				{
					high = mid - 1;
				}
			}

		}
	}
	return mid;
}

int main()
{
	int a[6] = { 4, 6 , -14, -10, -5, 3};
	cout<<search(a,6,3)<<endl;
	cout<<search(a,6,-14)<<endl;
	cout<<search(a,6,14)<<endl;
	cout<<search(a,6,-5)<<endl;
	cout<<search(a,6,-3)<<endl;
}
