#include<iostream>
#include<cmath>
#include<algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::next_permutation;

void printArray(long int arr[], int size){
	for(long int x=0;x<size-1;x++){
		cout << arr[x] << " ";
	}
	cout << arr[size-1] << endl;
}

int main() {
	long int N,K,tc;
	cin >> tc;
	while(tc--){
		cin >> N >> K;
		
		long int arr[N];
			for (long int i=0; i<N; i++) arr[i] = i+1;
		
		if(K==0) printArray(arr, N);
		else if( N%K !=0 || N % (2*K)!=0 ) cout << "-1"<< endl;
		else {
			bool odd=true;
			for(long int x=0;x<N-1;x++){
				if(odd)
					cout << arr[x]+K << " ";
				else cout << arr[x]-K << " ";
				
				if( (x+1) % K ==0 )odd=!odd;
			}
			cout << arr[N-1]-K << endl;
		}
		
			
	}
    return 0;
}

