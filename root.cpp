#include<iostream>

using namespace std;

float my_abs(float a){
	if(a> 0 ) return a;
	return -1 * a;
}

float squareroot(int a){
	if(a<=1){
		return a;
	}

	float delta_allowed = 0.00001;
	float start = 0;
	float end = a;
	while( start < end){
			float mid = (start + end)/2.0;
			if(my_abs(mid * mid - a) < delta_allowed){
				return mid;
			}
			else if(mid * mid > a){
				end = mid;
			}
			else {
				start = mid;
			}
	}
	return -1;
}

int main(){

	cout<<squareroot(4)<<endl;
	cout<<squareroot(2)<<endl;

	cout<<squareroot(101)<<endl;
	cout<<squareroot(0)<<endl;

}
