#include <bits/stdc++.h>																		
#define ll long long int																												
using namespace std;	

char ch;																			
int N;
ll arr[100005];

void update(int index, ll val)
{
	while(index <= N)
	{
		arr[index]+=val;
		index+=index&-index;
	}	
}

ll query(int index)
{
	ll abcd = 0;
	while(index > 0)
	{
		abcd+=arr[index];
		index-=index&-index; //komp 2
	}
	return abcd;
}

int main()
{
	int tc;
	
	cin >> tc;
	for(int t=0;t<tc;t++)
	{	
		int percobaan;
		ll temp; char ch;
		/*
		Input starts with an integer T (= 10), denoting the number of test cases.
		 Next line contains the integers N,Q 1=N, Q=10^5,  N is number of bag and Q is total work my brother and mother.
		 Next line there will be N integer A the initially pieces of marble put into bag. (0 = Ai = 10^9)
		*/
		cin >> N >> percobaan;
		memset(arr, 0, sizeof(arr));
		
		for (int x=1;x<=N;x++)
		{
			cin >> temp;
			update(x, temp);
			update(x+1, -temp);
		}
		
		printf("Case %d:\n",t);
		while(percobaan--)
		{
			cin >> ch;
			if(ch=='f')
			{
				int aa; cin >> aa;
				cout << query(t) << endl;
			}
			if(ch=='m')
			{
				int aa;
				cin >> aa;
				temp = query(aa);
				
				update(aa, -temp);
				update(aa+1, temp);
			}
			if(ch=='w'){
				int uu,vv;ll ww;
				cin >> uu >> vv >> ww;
				update(uu,ww);
				update(vv+1, -ww);
			}
			
		}
	}
	return 0;
	
}
