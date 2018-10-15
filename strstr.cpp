#include<iostream>

using namespace std;

int mystrstr(const char* str1, const char * str)
{
	int n = 0;
	int k = 0;
	if(str[k] == '\0')
		return 0;
	while(str1[n] != '\0')
	{
		k = 0;
		while(str[k] == str1[n+k])
		{
			k++;
			if(str[k] == '\0')
			{	
				return n;
			}
		}
		n++;
	}
	return -1;
}

int main()
{	
	cout<<mystrstr("sachinsachinsachin","achin");
	cout<<endl;
	cout<<mystrstr("achinsachinsachinsachin","achin");
	cout<<endl;
	cout<<mystrstr("sac","sacuh");
	cout<<endl;
	
}
