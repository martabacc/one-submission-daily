#include<bits/stdc++.h>
#define ll long long
#define moduLo 1000000007
using namespace std;
ll result;
int size;
string input;
vector<ll> numbers;
ll res;
ll sumofsubstring(int pos)
{
	if(pos==0) return numbers[0];
	else if(pos<size) 
	{
		result += (((ll)(pos+1) * numbers[pos]) + (10*sumofsubstring(pos-1)));
	}
	return result;

}

int main()
{
	
	cin >> input;
//	numbers.push_back(0);
	for(int x=0;x<input.size();x++)
	{
		numbers.push_back( input[x] - '0');
	}
	size = input.length();
	result = 0;
//	for(int x=0;x<numbers.size();x++) cout << numbers[x] << endl;
    cout << sumofsubstring(size-1) + 1 << endl;
    
}
