#include<bits/stdc++.h>
using namespace std;

bool cobacopyfunction(string a, string b)
{
	int aa = a.length();
	int bb = b.length();
	if(aa==bb) return a < b;
	else return aa<bb;
}

int main()
{
	int n; cin >> n;
	vector<string> cobadulu;
	string temp;
	for(int x=0;x<n;x++){
		
		getline(cin, temp);
		cobadulu.push_back(temp);
	}
		
	sort(cobadulu.begin(), cobadulu.end(), cobacopyfunction);
	
	for(int x=0;x<n;x++)
	{
		cout << cobadulu[x] << endl;
	}
}
