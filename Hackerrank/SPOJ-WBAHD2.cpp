#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>
#define REP(i,n) for(int i=0;i<(n);i++)
#define INF (-1<<30)
#define li long long int
using namespace std;

int main(){
	
	int tc;
	cin >> tc;
	REP(i, tc){
		int left, right;
		li tempLeft, tempRight;
		li sum=0;
		cin >> left >> right;
		
		for(int x=0;x<left;x++){
			li z; cin >> z;
			if(x==left-1) tempLeft =z;
			sum+=z; 
		}
		for(int x=0;x<right;x++){
			li z; cin >> z;
			if(x==right-1) tempRight =z;
			sum+=z; 
		}
		
		if(tempRight<tempLeft) sum-=tempLeft;
		else sum-=tempRight;
		
		cout<< "Case "<<i+1 << ": "<< sum<<endl;
		
		
	}
}
