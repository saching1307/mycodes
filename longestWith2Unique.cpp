#include<iostream>
#include<string>

using namespace std;

string findLongestUnique(string a)
{
	int length = a.length();
	int start = 0;
	int end = 0;
	for(int i = 0; i < length; i++)
	{	
		int j = i+1;
		char secondCharacter = '\0';
		while(a[i] == a[j])
		{
			j++;	
		}
		if( j < length && a[i]!=a[j])
		{
			secondCharacter = a[j];
		}
		while(a[j] == a[i] || secondCharacter == a[j])
		{
			j++;
		}
		if(end - start < j - i)
		{
			start = i;
			end = j - 1;
		}
	}
	return a.substr(start,end);
}

int main()
{
	string a = "abcbbbbcccbdddadacb";
	cout<<findLongestUnique(a)<<endl;
}
