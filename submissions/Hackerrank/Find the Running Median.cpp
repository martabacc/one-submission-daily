
#include <bits/stdc++.h>
#define pb push_back
using namespace std;


bool isEven(int number) {
  return number%2==0;
}

vector<float> runningMedian(vector<float> a) {
  priority_queue<int> minh, maxh;
  vector<float> res;
  float temp;

  float median = a[0];
  maxh.push(median);
  res.pb(median);

  for(int x=1;x<a.size();x++) {
    int now = a[x];

    if(!isEven(x)) {
      if(now <= median) maxh.push(now);
      else minh.push(-now);

      while(minh.size() != maxh.size()) {
        if(minh.size()!=(x/2)) {
          temp = -minh.top();
          minh.pop();
          maxh.push(temp);
        } else {
          temp = maxh.top();
          maxh.pop();
          minh.push(-temp);
        }
      }

      median = (float)(-minh.top() + maxh.top())/2.0;
    } else {
      /*
      // my previous solution
      // gotta figure out what's wrong with this one
      if(now <= median) maxh.push(now);
      else {
          temp = -minh.top();
          minh.pop();
          maxh.push(temp);
          minh.push(-now);
      }
      median = maxh.top();
      */

      if(minh.size() > maxh.size())
        median = -minh.top();
      else median = maxh.top();
    }
    res.pb(median);
  }

  return res;
}


int main()
{
  int tc;
  cin >> tc;
  vector<float> prob;
  float temp;
  while(tc--) {
    cin >> temp;
    prob.push_back(temp);
  }
  vector<float> res = runningMedian(prob);

  for(int x=0;x<res.size();x++) printf("%.1f\n", res[x]);
  return 0;
}
