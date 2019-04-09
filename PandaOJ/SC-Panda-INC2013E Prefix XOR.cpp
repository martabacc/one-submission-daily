#include<bits/stdc++.h>
using namespace std;

int result;

int main()
{
//	cout<<(11^10);
	int tc;
	cin >> tc;
	int cp = tc;
	while(tc--){
		result=0;
		int N;
		cin >> N; 
		int bil[N];
		map<int, int> occurence;
		int temp = 0;
		
		for(int z=0;z<N;z++)
		{
			cin >> temp;
			bil[z] = (z==0 ? 0 : bil[z-1]) ^ temp;
			if(bil[z]==0) result++;
			occurence[bil[z]]++;
		}
		
		for(pair<int,int> z : occurence)
		{
			if(z.second>=2)
				result += ( z.second * (z.second-1) )/2;
		}
		
		cout<< "Case #" << cp-tc << ": " << result<<endl;
	
		
	}
	return 0;
}
	
