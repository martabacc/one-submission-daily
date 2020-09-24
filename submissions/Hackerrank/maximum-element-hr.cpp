#include <bits/stdc++.h>
#define LL long long
using namespace std;


stack<LL> yourStack;
set<LL> yourVector;
LL x;
set<LL>::iterator it;
	
int tc, type;
int main() {
    cin>> tc;
    while(tc--){
        cin >> type;
        if(type==1){
            cin >> x;
            yourStack.push(x);
            yourVector.insert(x);
        }
        else if(type==2)
        {
            LL temp = yourStack.top();
            yourStack.pop();
            it = yourVector.find(temp);
            yourVector.erase(it);            
        }
        else if (type==3)
        {
            cout << *(yourVector.rbegin())<< endl;
        }
    }
    return 0;
}

