#include<iostream>
using std::cin;
using std::cout;
using std::endl;
typedef unsigned long long ULL;

int main(){
	ULL cases,n,ans;
	cin  >> cases;
	while(cases--){
		ans = 0ll;
		cin >> n;
		while(n>1){
			ans <<= 1;
			ans += n&1;
			n >>= 1;
		}
		cout << ans << endl;
	}
	return 0;
}

