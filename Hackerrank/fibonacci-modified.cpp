#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll t1, t2,n;
ll fibonacciMod[30];

ll findMod(ll res)
{
	
	if(fibonacciMod[res]==-1){
		fibonacciMod[res] = findMod(res-2) + (findMod(res-1)*findMod(res-1));
	}
//	cout << '[' << res << ']' << ':' << fibonacciMod[res] << endl;
	return fibonacciMod[res];
}
int main() {
    cin >> t1 >> t2 >> n;
    for(int x=0;x<30;x++){
    	fibonacciMod[x]=-1;
	}
    fibonacciMod[1] = t1;
    fibonacciMod[2] = t2;
    cout << findMod(n) << endl;
    return 0;
}

