#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define INF (-1<<30)
#define li long int
using namespace std;

int main(){

	int tc;
	cin >> tc;
	REP(i, tc){
		int left, right;
		cin >> left >> right;
		stack <li> leftQ;
		queue <li> rightQ;
		REP(le, left) {
			li x; cin >> x; leftQ.push(x);
		}
		REP(ri, right) {
			li x; cin >> x; rightQ.push(x);
		}
		li waitingtime=0;
		while(!leftQ.empty() || !rightQ.empty()){
			if(leftQ.empty()){
				if(rightQ.size()==1){
					 cout <<"Case " << i+1 << ": "<< waitingtime << endl;
				}
				else waitingtime+=rightQ.front() ;
				
				rightQ.pop();
			}
			else if(rightQ.empty()){
				if(leftQ.size()==1) cout  <<"Case " << i+1	 << ": "<< waitingtime << endl;
				else waitingtime+=leftQ.top();
				
				leftQ.pop();
			}
			else if(leftQ.top() < rightQ.front()) {
				waitingtime+=leftQ.top(); leftQ.pop();
			}
			else{
				waitingtime+=rightQ.front() ; rightQ.pop();
			}
		}	
		
	}
	return 0;
	
}

