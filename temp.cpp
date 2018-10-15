#include<iostream>
#include<map>

using namespace std;

void modify(string str, string s2, string s3)
{
	map<char, char> m1;
	for(int i=0;i<s2.length();i++)
	{
		m1[s2[i]] = s3[i];
	}

	int i=0;

	while(str[i] != '\0')
	{
		if(m1.count(str[i])>0)
		{
			cout<<m1[str[i]]<<" ";
			str[i] = m1[str[i]];
		}	
	
		i++;
	}
	cout<<str<<endl;
}

int main()
{
	string str1 = "Hello world";
	string str2 = "lod";
	string str3 = "xpf";
	modify(str1, str2, str3);
}
