#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>
#define INF (-1<<30)
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

int main(){
	int steps; cin >> steps;
	vector < pair<int,int> > heights;
	int temp;temp=INF;
	
	REP(i,steps){
		int height; cin >> height;
		if ( height > temp ){
			temp = height;
			heights.push_back( make_pair( height , i+1) );
		}
	}
	int query;
	cin >> query;
		
	REP(i,query){
		int q; cin >> q;
		
		bool flag = false;
		for(int x=0;x<heights.size();x++){
			pair<int,int> stairNow = heights[x];
			if(q < stairNow.first){
				cout << stairNow.second << endl;
				flag = !flag;
				break;
			}
		}
		if(!flag) cout << "NO SE TROPIEZA"<<endl;
		
	}
	
	
}
