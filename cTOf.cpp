#include<iostream>

using namespace std;

float cTOf(float input)
{
	return input * 9/5.0 + 32;
}
int main(){
	float input;
	cin>>input;
	cout<<cTOf(input)<<endl;
}
