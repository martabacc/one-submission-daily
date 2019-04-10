/*
 * Hackerrank
 * Jesse and Cookies
 * https://www.hackerrank.com/challenges/jesse-and-cookies/problem
 *
 * Heap, priority_queue
 */

#include<bits/stdc++.h>
using namespace std;

int howManyOperations(int k, vector<int> A) {
    priority_queue<int> pq;
    for(int x=0;x<A.size();x++) pq.push(-A[x]);
    int operations = 0;

    while(!pq.empty()){
        int leastSweet = -pq.top();
        if(pq.size()==1 && leastSweet < k ) return -1;
        if(leastSweet >= k) return operations;

        pq.pop();
        int moreSweet = -pq.top();
        pq.pop();

        int newSweetness = -((1*leastSweet) + (2*moreSweet));
        operations++;
        pq.push(newSweetness);
    }

    return -1;
}

int main() {
  int N, K, temp;
  cin >> N >> K;
  vector<int> cookies;
  for(int x=0;x<N;x++) {
    cin >> temp;
    cookies.push_back(temp);
  }
  cout << howManyOperations(cookies) << endl;
  return 0;
}
