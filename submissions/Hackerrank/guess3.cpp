#include<iostream>
#include<string>
using namespace std;

int main(){
	string x;
	getline(cin,x);
	int a=0;int b=0;
	bool lewat = false;
	for(int y=0; y< x.length();y++){
		if(!lewat){
			if( x[y]!='.'){
				int z = (int) x[y] - 48;
				a*=10; a+=z;
			}
			else{
				lewat=true;
			}
		}
		else{
				int z = (int) x[y]  - 48;
				b*=10; b+=z;
		}
	}
	for(int y=a;y<=b;y++)
		cout << y << ' ' ;
		
	cout << endl;
	
}

