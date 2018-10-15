#include<iostream>
#include<stack>

using namespace std;

int calcExpression(const char* experssion)
{
    int answer = 0, i=0;
    stack<int> *numberStack = new stack<int>();
    while(experssion[i] != '\0')
    {
        if(experssion[i] == '*')
        {
           int n = numberStack->top();
	   numberStack->pop();
           numberStack->push((experssion[++i] - '0') * n);
        }
        else if(isdigit(experssion[i]))
        {
            numberStack->push((experssion[i] - '0'));
        }
        i++;
    }
    
    int sum = 0;
    while(numberStack->empty() == false)
    {
        sum += numberStack->top();
        numberStack->pop();
    }
	return sum;
}

int main()
{
	cout<<calcExpression("2+4*5*6")<<endl;
}
