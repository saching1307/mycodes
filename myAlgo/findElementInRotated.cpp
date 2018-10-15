#include<iostream>

using namespace std;

int pivot(int a[],int low, int high)
{
	int mid = (low + high)/2;
	if(a[mid] < a[mid-1])
	{
		return mid;
	}	
	else
	{
		if(a[mid] > a[mid-1])
			return pivot(a,mid+1,high);
		else
			return pivot(a,low,mid);
	}
}

int binarySearch(int a[],int low, int high,int ele)
{
	int mid = (low + high)/2;
	if(a[mid] == ele)
		return mid;
	else if(low >= high && a[low]!=ele)
		return -1;
	else if(a[mid] < ele)
		return binarySearch(a,mid+1,high,ele);
	else
		return binarySearch(a,low,mid,ele);
}

int search(int a[],int arraySize, int ele)
{
	if(arraySize == 0 )
		return false;
	if(arraySize==1)
		return a[0]==ele;
	else
	{
		int pivotPosition = pivot(a,0,arraySize-1);
		int foundPos = binarySearch(a,0,pivotPosition-1,ele);
		if(foundPos == -1)
			foundPos= binarySearch(a,pivotPosition,arraySize-1,ele);
		if(foundPos != -1)
			return foundPos;
	}
	return -1;
}

int main()
{
	int a[] = {1,2,5,9,100,-21, -20, 0};
	int n = 8;
	while(1)
	{
		cin>>n;
		cout<<search(a,8,n)<<endl;
	}
}
