#include<iostream>
#include<vector>

using namespace std;

int getIntFromBinaryString(string v){
		int output = 0;
		for(int i=0; i <v.size() ; i++){
			output = output * 2 + v[i] - '0';
		}
		return output;
}

int sumBinaryString(string v1, string v2){
	return getIntFromBinaryString(v1) + getIntFromBinaryString(v2);
}

int main(){

	string v1 = "10001";
	string v2 = "100111";

	cout<<sumBinaryString(v1, v2);
}
