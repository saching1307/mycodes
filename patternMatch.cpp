#include<iostream>

using namespace std;

bool matchPattern(const char* text, const char* pattern)
{
	if(text[0] == '\0') return pattern[0] == '\0';
	if(pattern[0] == '\0') return text[0]=='\0';

	if(pattern[1] == '*')
	{
		int i=0;
		while(pattern[0] == text[i] ||  pattern[0]=='.')
		{
			i++;
			if(text[i] == '\0')
				break;	
		}
		return matchPattern(text+i, pattern+2);

	}
	else
	{
		if(pattern[0] == '.')
			return matchPattern(text + 1, pattern + 1);
		if(pattern[0] != text[0])
		{
			return false;
		}
		else 
			return matchPattern(text + 1, pattern + 1);
	}
}

bool matchPattern1(const char* text, const char* pattern)
{
	int i=0, j=0;
	while(text[j] != '\0')
	{
		char patternLastChar = pattern[i-1];
		if(pattern[i] == '*')
		{
			if(pattern[i - 1] == '.')
				return true;
			else
			{
				if(text[j] == patternLastChar)
				{
					while(text[j] == patternLastChar)
					{
						if(text[j] == '\0') 
						{	
							if(pattern[i+1] == '\0')
							{
								return true;
							}
							else
							{
								return false;
							}
						}
						j++;
					}
				}
			}
		}
		else if(pattern[i] == '.')
		{
			;
		}	
		else if(pattern[i] != text[j] && pattern[i+1]!='*') 
		{
			return false;
		}
		else
		{
			j++;
		}
		i++;
		if(pattern[i] == '\0')
			break;
	}
	if(pattern[i] == '\0' && text[j] == '\0')
		return true;
	else
		return false;

}

int main()
{
	string pattern = "ab*c.*";
	string text;
	//cout<<matchPattern(pattern, text)<<endl;
	cout<<matchPattern("aa","a");
	cout<<endl;
	cout<<matchPattern("aa","aa");
	cout<<endl;
	cout<<matchPattern("aaa","aa");
	cout<<endl;
	cout<<matchPattern("aa", "a*");
	cout<<endl;
	cout<<matchPattern("aa", ".*");
	cout<<endl;
	cout<<matchPattern("ab", ".*");
	cout<<endl;
	cout<<matchPattern("aab", "c*a*b");
	cout<<endl;
}
