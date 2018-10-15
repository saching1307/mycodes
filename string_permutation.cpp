#include<iostream>

using namespace std;

void print_string_permutaion(string input, string prefix, int start, int end){
	 	if(start == end){
				cout<<input<<" "<<endl;
				return;
		}

		for(int i=start; i< end; i++){
						swap(input[i], input[start]);
						print_string_permutaion(input, prefix + input[i], start+1, end);
						swap(input[i], input[start]);
		}
		return;
}

int main(){
		string input = "abasdjknc";
		print_string_permutaion(input, "", 0, input.length());
}
