#include<bits/stdc++.h>
#define maxN 1000
using namespace std;
#define inf 9999.9999


struct Graph{
	int seq, visitedTimes, x, y;
	Graph* min1, min2;
}

float min1, min2;

Graph* newGraph(int seq){
	Graph* temp = new Graph;
	temp->seq = seq;
	return temp;
}

float getDistance(int x1, int x2, int y1, int y2)
{
	return (float)sqrt(pow(x2-x1,2)-pow(y2-y1,2));
}

int main(){
	int N;
	cin >> N;
	while(N!=0)
	{
		//reinitiate
		min1=inf;
		min2=inf;

		int m;
		cin >> m;
		int arr[m][2];
		float inverted[m][m];

		// for transmitter
		for(int x=0;x<m;x++)
		{
			cin >> arr[x][0] >> arr[x][1];
			for(  )
		}
		
		
		
		


	}

}
