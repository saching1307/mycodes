#include<iostream>

using namespace std;

/* Function to swap values at two pointers */
void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char*a,int i, int n)
{
	if(i==n)
	{
		cout<<a<<endl;
		return;
	}

	for(int j=i;j<n;j++)
	{
		swap(a+i,a+j);
		permute(a,i+1,n);
		swap(a+i,a+j);
	}

}

int main()
{
	char *a;
	a = (char*) malloc(sizeof(char)*10);
	int n;
	cin>>a>>n;
	permute(a,0,n);
}
