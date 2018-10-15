
#include<iostream>

using namespace std;

#define swap(x,y) { x = x + y; y = x - y; x = x - y; }

void print(int a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;

}

void partition(int* a, int low, int high, int pivot)
{
	int pvot = a[pivot];//rand()%(right-left) + left;
	int i   = low;
	int j = high;
	while(i <= high && j>=0 && i < j)
	{   
		while(a[i] > pvot)
			i++;
		while(a[j] < pvot)
			j--;
		if(a[i]<a[j] && i <j)
		{    
			a[i] = a[i] + a[j];
			a[j] = a[i] - a[j];
			a[i] = a[i] - a[j];
		}   
		i++;
		j--;
	}   
}

void quickSort(int *a, int left, int right)
{
	int mid = (left+right)/2;
	if(left < right)
	{
		partition(a,left,right,mid);
		quickSort(a, left,mid);
		quickSort(a, mid+1,right);
	}
}

int main()
{
	int n = 6;
	int *a;
	a=(int*)malloc(sizeof(int)*n);	
	for(int i=0;i<n/2;i++)
	{
		a[i] = rand()%100 * (rand()%2 ? -1 : 1);
		a[n-1-i] = a[i];
	}
	print(a,n);
	quickSort(a,0,n-1);
	print(a,n);
	return true;
}
