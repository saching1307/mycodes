#include<iostream>

using namespace std;

int myatoi(const char* str)
{
	int sign = 1;
	int sum = 0;
	int i=0;
	while(str[i]!='\0')
	{
		if( isspace(str[i]) || str[i]=='\"')
		{
			i++;
		}
		else
		{
			break;
		}
	}

	if(str[i]=='-')
	{
		i++;
		sign  = -1;
	}
	else if( str[i]=='+')
		i++;


	cout<<sum<< " ss"<<i<<str[i]<<endl;
	while(str[i]!='\0')
	{
		if(str[i] <= '9' && str[i] >='0')
		{

			if(sum > str[i] - '0' + sum * 10)
			{
				if(sign > 0)
					return 2147483647;
				else
					return -2147483648;
			}
			sum = str[i] - '0' + sum * 10;
		}
		else                    
			break;
		i++;
	}
	return sum*sign;
}
int  main()
{
	char n[1000];
	cin>>n;
	cout<<myatoi(n)<<endl;
	return true;
}
