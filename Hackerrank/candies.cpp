#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define fori(z) for(ll i=0;i<z;i++)
using namespace std;

//not implementing dynamic programming, 
// still thinking how to implement in dp tho

vector<ll> ratings;
vector<ll> candies;
int main() {
	ll N, temp;
	cin >> N;
	
	fori(N) {
		cin >> temp;
		ratings.pb(temp);
		if(i==0) candies.pb(1);
		else{
			if(ratings[i-1] < temp) candies.pb(candies[i-1]+1);
			else candies.pb(1);
		}
	}
	
	for(ll iter=N-1;iter>0;iter--){
		if(ratings[iter-1] > ratings[iter] )
			if(candies[iter-1] <= candies[iter])
				candies[iter-1]= candies[iter] + 1; 		
	}
	
	temp = 0;
	fori(N) {
//		cout << candies[i] << " ";
		temp += candies[i];
	}
//	cout << endl;	
	cout << temp << "\n";
	
	
	
	
	return 0;
	
}

