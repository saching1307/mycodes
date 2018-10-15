#include<iostream>

using namespace std;

class test
{
	private:
		void * operator	new(size_t size);
		int x;
	public:
		test(){x=10;}
		~test(){;}
		void display() {cout<<x<<endl;}
};

int main()
{
	int p[]= {8,20,40,60};
	int *arr = p;
	cout<<*arr++<<" "<<*++arr<<" "<<++*arr<<endl;
}
