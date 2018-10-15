#include<iostream>
#include<string>

using namespace std;

int myatoi(const char * string)
{
	/* To consider
		"109" = 109
		"1.09" =  1
		"1.9.9" = 1
		"-1.9" = -1
	*/
	
	int sum = 0;
	if(string == NULL || strlen(string) == 0) 	return 0;
	bool isNegative = string[0] == '-' ? true : false;
	int index = isNegative ? 1 : string[0] == '+' ? 1: 0;
	while(1)
	{
		if(string[index] >= '0' && string[index] <= '9')
		{
			sum = sum * 10 + string[index] - '0';
			index++;
		}
		else
		{
			break;
		}
	}
	return isNegative ? sum * -1 : sum;

}
int main()
{
	cout<<myatoi("+1019")<<endl;
	cout<<myatoi("1.09")<<endl;
	cout<<myatoi("1.9.9")<<endl;
	cout<<myatoi("-1.9")<<endl;
	cout<<myatoi("0.00001")<<endl;
	cout<<myatoi(NULL)<<endl;
}
