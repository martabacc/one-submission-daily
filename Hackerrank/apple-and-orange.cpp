#include<bits/stdc++.h>
using namespace std;

int s,t,b,a,m,n;
int apple, orange;
int temp;

void countApple(int pos){
	if(pos+a<= t && pos+a >= s) apple++;
}
void countOrange(int pos){
	if(pos+b<= t && pos+b >= s) orange++;
}


int main(){
	cin >> s >> t >> a >> b >> m >> n;
	
	apple=0;
	orange=0;
	for(int x=0;x<m;x++)
	{
		cin >> temp;
		countApple(temp);
	}
	for(int x=0;x<n;x++)
	{
		cin >> temp;
		countOrange(temp);
	}
	
	cout << apple << " " << orange << endl;
	return 0;
	
}
