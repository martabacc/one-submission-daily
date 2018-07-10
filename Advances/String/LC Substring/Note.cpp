#include<bits/stdc++.h>
#define max 99999999
#define ll long long
using namespace std;
// please delete after
// BC-<order>-<topic>-LEFT(10, subTopic)
// IM-<order>-<topic>-LEFT(10, subTopic)
// SJ-<Name of OJ>-ProblemCode

ll size = 8;
ll divider[] = {10934,300234,393939,20000,3848482,393939,7777,11111139};
ll lala;

void testA(vector<ll> &a)
{
	for(ll x=a.size();x>=0;x--)
	{
		lala = a[x]% divider[x%size];
	}
}

void testB(vector<ll> *a)
{
	for(ll x=(*a).size();x>=0;x--)
	{
		lala = (*a)[x] % divider[x%size];
	}
	
}

int main()
{	
	vector<ll> tc;
	ll la = max;
	while(--la) tc.push_back(la);
	
	  clock_t begin = clock();

	  testA(tc);
	  clock_t end = clock();
	  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	  cout << elapsed_secs << endl;
	  
	  begin = clock();
	  testB(&tc);
	  end=clock();
	  elapsed_secs=double(end-begin)/CLOCKS_PER_SEC;
	  cout << elapsed_secs << endl;

	return 0;
}



