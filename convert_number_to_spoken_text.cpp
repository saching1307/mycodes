#include<iostream>
using namespace std;

string get_single_text(int n){
		string output = "";
		if(n==0){
				return "zero";
		}
		if(n==1){
				return "one";
		}
		if(n==2){
				return "two";
		}
		if(n==3){
				return "three";
		}
		if(n==4){
				return "four";
		}
		if(n==5){
				return "five";
		}
		if(n==6){
				return "six";
		}
		if(n==7){
				return "seven";
		}
		if(n==8){
				return "eight";
		}
		if(n==9){
				return "nine";
		}
		if(n==10){
				return "ten";
		}

		if(n==11){
				return "eleven";
		}
		if(n==12){
				return "twelve";
		}
		if(n==13){
				return "thirteen";
		}
		if(n==14){
				return "fourteen";
		}
		if(n==15){
				return "fifteen";
		}
		if(n==16){
				return "sixteen";
		}
		if(n==17){
				return "seventeen";
		}
		if(n==18){
				return "eighteen";
		}
		if(n==19){
				return "nineteen";
		}
		if(n==20){
				return "twenty";
		}
		if(n==30){
				return "thirty";
		}
		if(n==40){
				return "fourty";
		}
		if(n==50){
				return "fifty";
		}
		if(n==60){
				return "sixty";
		}
		if(n==70){
				return "seventy";
		}
		if(n==80){
				return "eighty";
		}
		if(n==90){
				return "ninety";
		}


		if(n > 19 && n < 99){
				output = "";
				return get_single_text(n/10 * 10) + " " + get_single_text (n%10);
		}

		if(n >= 1000000000000){
				output += " " +  get_single_text(n/1000000000000) + " trillion ";
				n = n%1000000000000;
		}

		if(n >= 1000000000){
				output += " " +  get_single_text(n/1000000000) + " billion ";
				n = n%1000000000;
		}

		if(n >= 1000000){
				output += " " + get_single_text(n/1000000) + " million ";
				n = n%1000000;
		}

		if(n >= 1000){
				output += " " +  get_single_text(n/1000) + " thousand ";
				n = n%1000;
		}

		if(n >= 100){
				output += " " +  get_single_text(n/100) + " hundred ";
				n = n%100;
		}

		if(n > 0 || output.size() == 0){
			output += " " +  get_single_text(n);
		}

		return output;
}


int main(){
	cout<<get_single_text(124)<<endl;
	cout<<get_single_text(1213124)<<endl;
	cout<<get_single_text(12131344)<<endl;
	cout<<get_single_text(12214)<<endl;

}
