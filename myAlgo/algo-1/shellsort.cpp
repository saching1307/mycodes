#include<iostream>

using namespace std;

void print(int *a,int n=7)
{
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<< " ";
}
void shellSort(int *a,int n)
{
	int h = 1;
	while( h < n/3) 
		h = 3*h + 1;
	
	while(h>=1)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j+=h)
			{	
				if(a[i]>a[j])
				{
					int temp = a[i];
					a[i]=a[j];
					a[j] = temp;
				}

			}
		}
		print(a);
		h/=3;
	}
}


int main()
{

	int a[]= {2,2342,1231,22,33,1112,3444};
	print(a);
	shellSort(a,7);
	return true;
}
