#include<bits/stdc++.h>
using namespace std;

string numberToWord(int number){
	switch(number){
		case 1: return "one";
		case 2: return "two";
		case 3: return "three";
		case 4: return "four";
		case 5: return "five";
		case 6: return "six";
		case 7: return "seven";
		case 8: return "eight";
		case 9: return "nine";
		case 10: return "ten";
		case 11: return "eleven";
		case 12: return "twelve";
		case 13: return "thirteen";
		case 14: return "fourteen";
		case 15: return "quarter";
		case 20: return "twenty";
		case 21: return "twenty one";
		case 22: return "twenty two";
		case 23: return "twenty three";
		case 24: return "twenty four";
		case 25: return "twenty five";
		case 26: return "twenty six";
		case 27: return "twenty seven";
		case 28: return "twenty eight";
		case 29: return "twenty nine";
		case 30: return "half";	
		default: return "o' clock'";
	}
}

void saidIt(int H, int M)
{
//	if( M % 15 ){ // not exact in quarter
		if(M==0) cout << numberToWord(H) << " o' clock\n";
		if( M <= 30 ){
			cout << numberToWord(M) << ((M%15) ? ( (M>1) ? " minutes" : " minute") : "" )<< " past " << numberToWord(H) << "\n";
		}
		else{
			cout <<  numberToWord(60-M) <<  ((M%15) ? ((60-M>1) ? " minutes" : " minute") : "") << " to " << numberToWord(H+1)<< "\n"; 
		}
}

int main()
{
	int H, M;
	cin >>  H >> M;
	saidIt(H,M);
	return 0;
}
