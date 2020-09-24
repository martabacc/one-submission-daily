#include<iostream>
using namespace std;

int main(){
	long int n, k,b;
	cin >> n >> k;
	long int costNotEatenByAnna, sumAllPrice;
	for(int x=0;x<n;x++) {
		if(x==k) cin >> costNotEatenByAnna;
		else{
			long int y; cin >> y;
			sumAllPrice += y;
		}
	}

	cin >> b;
	if(sumAllPrice/2 != b) cout << b - (sumAllPrice/2) <<endl;
	else cout << "Bon Appetit" << endl;

	return 0;
}
