#include<iostream>
using namespace std;

int  check_palindrom_one_mistake(string s, int ignore_index){
		int start = 0;
		int end = s.size() -1;
		while(start < end){
			if(ignore_index == start){
				start++;
				continue;
			}

			if(ignore_index == end){
				end--;
				continue;
			}

			if(s[start] != s[end]){
					return false;
			}
			start++;
			end--;
		}

		return true;
}


int  check_palindrom(string s){
		int start = 0;
		int end = s.size() -1;
		while(start < end){
				if(s[start] != s[end]){
					if(check_palindrom_one_mistake(s, start) || check_palindrom_one_mistake(s, end)){
							;
					} else{
						return false;
					}
			}
			start++;
			end--;
		}

		return true;
}


int main(){
	cout<<check_palindrom("abcdefcba")<<endl;
	cout<<check_palindrom("abcdcba")<<endl;
	cout<<check_palindrom("abcddcba")<<endl;
}
