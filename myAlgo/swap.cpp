#include<iostream>

int main()
{
	int a=10,b=10;
	a = *(&a) ^ *(&b);
	b = *(&a) ^ *(&b);
	a = *(&a) ^ *(&b);
	std::cout<<a<< " "<<b<<std::endl;
}
