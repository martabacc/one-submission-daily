#include<bits/stdc++.h>
using namespace std;

string inp;
double get


int main(){
  int tc, N;
  cin >> tc;
  while(tc--) {
    cin >> N;
    double sum = 0.0;
    int speedD=0.2, speedF=0.2, speedJ=0.2, speedK = 0.2;
    for(int x=0;x<N;x++){
      cin >> inp;
      for(int x=0;x < inp.size(); x++){
        sum += getTypeSpeed(x);
      }
    }
  }
}
