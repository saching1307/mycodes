#include<iostream>
#include<stack>
#include<string>

using namespace std;


void calculatePostFix(string input[], int n)
{
	stack<int> s1;
	for(int i=0;i<n;i++)
	{
		if(input[i].compare("+") == 0)
		{
			int top1= s1.top();	
			s1.pop();
			int top2 = s1.top();
			s1.pop();
			s1.push(top1+top2);
		}
		else if(input[i].compare("-") == 0)
		{
			int top1= s1.top();	
			s1.pop();
			int top2 = s1.top();
			s1.pop();
			s1.push(top2-top1);
		}
		else if(input[i].compare("*") == 0) 
		{
			int top1= s1.top();	
			s1.pop();
			int top2 = s1.top();
			s1.pop();
			s1.push(top1*top2);
		}
		else if(input[i].compare("/") == 0)
		{	
			int top1= s1.top();	
			s1.pop();
			int top2 = s1.top();
			s1.pop();
			s1.push(top2/top1);
		}
		char* temp;
		int value = strtol(input[i].c_str(), &temp, 0);
		if(*temp=='\0')
		{
			s1.push(value);
		}
		
	}
	cout<<s1.top();
}

int main()
{
	int n=5;
	string input[] = {"2", "3" , "+", "1", "-"};
	calculatePostFix(input,n);
}
