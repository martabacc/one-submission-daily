#include <bits/stdc++.h>

using namespace std;
long candleCounter[10000000];

//memset(candleCounter,0,sizeof(candleCounter));

int birthdayCakeCandles(int n, vector <int> ar) {
	long max = -9999;
	long ptr = 0;
    // Complete this function
    for(int x=0;x<ar.size();x++)
	{
    	if(ar[x] > max)	{
    		ptr = 1;
    		max = ar[x];
		}
		else if(max==ar[x]) ptr++;
	}
	return ptr;
	
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(long x = 0;x<10000000;x++) candleCounter[x]=0;
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    
    cout << birthdayCakeCandles(n, ar) << endl;
    return 0;
}

