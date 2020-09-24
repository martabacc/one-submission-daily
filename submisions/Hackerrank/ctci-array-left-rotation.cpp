#include<bits/stdc++.h>
#define LIM 9999
#define loopx(X) for(int x=0;x<X;x++)
#define loopy(X) for(int y=0;y<X;y++)
using namespace std;

int main()
{

	int x,y;
	cin >> x >> y;
	long arr[x];
	
	loopy(x)
	{
		cin >> arr[y];
	}
	
	for(int a=y;a<x;a++)
	{
		cout << arr[a] << " ";
	}
	
	for(int a=0;a<y;a++)
	{
		cout << arr[a] << " ";
	}
	cout << endl;
}

