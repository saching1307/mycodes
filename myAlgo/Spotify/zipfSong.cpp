#include<iostream>

using namespace std;

class song
{
	public:
		int timesPlayed;
		char nameOfSong[1000];
		int zFactor;
		song(int a, int z,char  *name)
		{	
			zFactor =z;
			strcpy(nameOfSong, name);
			timesPlayed = a;
		}
};

int compare(const void *a, const void* b)
{
	song* temp1 = *(song**)a;
	song* temp2 = *(song**)b;
	return -temp1->zFactor + temp2->zFactor; 
}

int main()
{
	int n;
	cin>>n;
	int output;
	cin>>output;
	song** songArray;
	songArray = (song**)malloc(sizeof(song*)*n);
	int zFactor = 1;
	for(int i=0;i<n;i++)
	{
		int numberOfTimesPlayed =0;
		char* a = (char*)malloc(sizeof(char)*100);
		cin>>numberOfTimesPlayed;
		cin>>a;
		int z = numberOfTimesPlayed * zFactor;
		songArray[i] = new song(numberOfTimesPlayed,z,a);
		zFactor = (i+2);
	}
	
	qsort (songArray, n, sizeof(song*), compare);
	cout<<endl;
	for(int i=0;i<output;i++)
	{
		song* temp = songArray[i];
		cout<<temp->nameOfSong<<endl;
	}	

}
