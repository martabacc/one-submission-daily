#include<iostream>
#include<string>
using namespace std;

int main(){

	int z;
	cin >> z;
	while(z--){
		char before;
		before = '-';
		int count; count=0;
		string o;
		cin >> o;
//		cout << o.length();
		for(int x=0;x<o.length();x++){
			char y = o[x];
			if(before=='-') before=y;
			else{
				if(before==y)count++;
				else before=y;
			}		
		}
		cout << count << endl;
	}
	return 0;
}

