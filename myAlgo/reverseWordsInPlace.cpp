#include<iostream>

using namespace std;

void printReverse(string s)
{
	if(s.length()==0)
		return;
	int i=0;
	
	while(!isspace(s[i]) && s[i]!='\0')
	{
		i++;
	}
	
	for(int j=0;j<i/2;j++)
	{
		char temp = s[i-j-1];
		s[i-j-1] = s[j];
		s[j] = temp;
	}

	string reversedS = s.substr(0,i);
	cout<<reversedS<<" ";

	if(s.length() > i+1)	
	{
		string newS = s.substr(i+1);	
		printReverse(newS);
	}
}
	
int main()
{
	string s="This is my home town";
	cout<<s<<endl;
	printReverse(s);
	cout<<endl;
}
