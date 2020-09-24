#include<bits/stdc++.h>
#define ll long long
#define loop(x) for(long long iterloop=1;iterloop<x+1;iterloop++)
using namespace std;
pair<ll, ll> trace[2];

int howManySpaceLeft()
{
	if(trace[2].first==0) return 1;
	if(trace[1].first==0) return 2;
	
	return 0;
}

int isintrace(ll needle){
	if(trace[2].first==needle) return trace[2].second;
	if(trace[1].first==needle) return trace[1].second;
	return 0;
}
void empty_trace()
{
	pair<ll,ll> temp = make_pair(0,0);
	trace[0] = temp;
	trace[1] = temp;
}

int main()
{
	
	ll temp, lala;
	cin >> lala;
	ll arr[lala+2], pos[lala+2];
	map<ll,ll> flag;
	ll ptr_iter=0;
	
	loop(lala)
	{
		cin >> temp;
		arr[iterloop] = temp;
		if(!flag[temp]){
			flag[temp] = iterloop;
			pos[iterloop]=iterloop;
		}
		else{
			pos[iterloop] = flag[temp];
			flag[temp] = iterloop;
		}
	}
	
	
	empty_trace();
	loop(lala)
	{
		if()
	}
	
}

