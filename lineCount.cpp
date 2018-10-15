#include<iostream>

using namespace std;

int main(){
	FILE* fp = fopen("input","r");
	char ch ;
	int lines = 0 ;
	fscanf(fp,"%c",&ch);
	while(ch!=EOF && !feof(fp)){
		cout<<ch;
		if(ch == '\n') lines++;
		fscanf(fp,"%c",&ch);
	}
	
	cout<<"number of lines are::"<<lines<<endl;
	fseek(fp,0,SEEK_END);
	long size=ftell (fp);
	cout<<"size of file is :::"<<size<<endl;
}
