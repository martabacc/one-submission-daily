#include<bits/stdc++.h>
#define ll long long
#define MODULO 	1000000007
using namespace std;
ll result;
int size;
string input;
vector<ll> numbers;
ll res;
vector<ll> sumofdigit;
ll sumofsubstring()
{
	ll result;
	result = numbers[0];
	sumofdigit.push_back(result);
	
	sumofdigit[0] = result;
	for(ll x=1;x<input.length();x++)
	{
		sumofdigit.push_back( (((x+1) * numbers[x])%MODULO + (10*sumofdigit[x-1])%MODULO) % MODULO );
//		sumofdigit[x] = sumofdigit[x]%moduLo;
//		cout << sumofdigit[x] << endl;
		result = (result%MODULO + sumofdigit[x]%MODULO)%MODULO;
	}

	return result% MODULO;

}

int main(){
	cin >> input;
//	numbers.push_back(0);
	for(ll x=0;x<input.size();x++)
	{
		numbers.push_back(input[x] - '0');
	}
	
//	for(int x=0;x<numbers.size();x++) cout << numbers[x] << endl;
    cout << sumofsubstring()<< endl;
	
	
}
