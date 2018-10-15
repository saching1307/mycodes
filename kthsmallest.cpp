#include<iostream>

using namespace std;
int kthLargest(int *a, int start, int end, int k)
{
	if(start >= end) return -1;
	int pivotIndex = rand()%(end-start);
	int pivot = a[pivotIndex];

	int i=0, j=end-1;
	while(j > i)
	{	
		while(a[i] < a[pivotIndex])
		{
			i++;
		}
		
		while(a[j] > a[pivotIndex])
		{
			j--;
		}
		
		if(a[i] > pivot && a[j] < pivot)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		else if(a[i] > pivot)
		{
			a[pivotIndex] = a[i];
			a[i] = pivot;
			pivotIndex = i;
		}
		else if(a[j] < pivot)
		{
			a[pivotIndex] = a[j];
			a[j] = pivot;
			pivotIndex = j;
		}
	}
	if(pivotIndex == k) return a[pivotIndex];
	else if(pivotIndex < k) return kthLargest(a, pivotIndex + 1, end, k);
	else return kthLargest(a, start, pivotIndex - 1, k);
}

int main()
{
	int n=10;
	int a[n];
	for(int i=0;i<n;i++)
	{
		a[i] = rand()%100012;
	}
	for(int i=0;i<n;i++) 
		cout<<a[i]<<" ";
	{
		cout<<endl;
		cout<<kthLargest(a,0, n, 0);
		cout<<endl;
	}
}

