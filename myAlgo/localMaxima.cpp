#include<iostream>

using namespace std;
int maximum(int arr[],int n)
{
	if(n==1)
		return arr[0];
	if(n==2)
		return max(arr[0],arr[1]);
	int mid = n/2;
	if(arr[mid] < arr[mid+1])
	{
		return maximum(arr + mid,n - n/2);
	}
	else
		return maximum(arr,mid);
}

int main()
{
	int arr[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
	int n = 11;
	cout<<maximum(arr,n)<<endl;

	int arr1[] = {1, 3, 50, 10, 9, 7, 6};
	n=7;
	cout<<maximum(arr1,n)<<endl;

	int arr2[] = {10, 20, 30, 40, 50}; n=5;
	cout<<maximum(arr2,n)<<endl;
	int arr3[] = {120, 100, 80, 20, 0}; n =5;
	cout<<maximum(arr3,n)<<endl;
}
