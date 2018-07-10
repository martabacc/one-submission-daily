#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long in[5];
	long long temp;
	for(int x=0;x<5;x++) cin >> in[x];

	//sorting
	for(int x=0;x<4;x++){
		for(int y=x+1;y<5;y++){
			if(in[x] > in[y]){
				//swap
				temp = in[x];
				in[x] = in[y];
				in[y] = temp;
			}

		}
	}
	temp = 0;
	long long max = 0;
	for(int x=0;x<5;x++){
		if(x!=0) max+=in[x];
		if(x<4) temp+=in[x];
	}
	cout << temp << " " << max << endl;

	return 0;
}
