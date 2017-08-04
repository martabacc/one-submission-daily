#include<iostream>
#include<vector>
#include<cstdio>
#include <cstring>
#include<algorithm>
#include<stack>
using namespace std;


#define REP(i,n) for(int i=0;i<(n);i++)
#define INF (1<<30)
typedef pair<int,int> PII;
stack<int> lala;

void resetStack(){
	while(!lala.empty() ) lala.pop();
}





int findPossibilities(vector<int> lala){
	
}

vector<int> VI;
int n, k;

int main(){

	int tc;
	cin >> tc;
	while(tc--){
		cin >> n >> k;
		for(int x=0; x<=n;x++){
			char a;
			int temp;
			if(x%2==0) {
				scanf("%c",&a);
			}else{
				scanf("%d",&temp);
				if(a=='-') {
					VI.push_back(-temp);
					
				}
				else VI.push_back(temp);
			}
		}
		
		REP(i,n/2){
			cout << VI[i] << endl;}
			
		int z = findPossibilities(VI);
		
		VI.clear();
		}
	return 0;
}

