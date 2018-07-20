
/*
 * Hackerrank
 * Mountain Climbing
 * https://www.hackerrank.com/challenges/ctci-coin-change/problem
 *
 * Optimized DP
 * Ref: https://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
 */


#include<iostream>
#define ll long long
using namespace std;

// Complete the ways function below.
ll ways(int count, int sum, vector<int> coins) {
    ll dp[sum+1][count];
    for(int x=0;x<count;x++) dp[0][x] = 1;

    for(int x=1;x<sum+1;x++)
        for(int y=0;y<count;y++){
            ll subtractLast = (x-coins[y] >= 0) ? dp[x-coins[y]][y] : 0;
            ll ignoreLast = ( y >= 1 ) ? dp[x][y-1] : 0;
            dp[x][y]= subtractLast + ignoreLast;
        }

    return dp[sum][count-1];
}

int main(){
    int sum, count, temp;
    cin >> sum >> count;
    vector<int> coins;
    for(int x=0;x< count;x++){
        cin >> temp;
        coins.push_back(temp);
    }


    ll result = ways(count, sum, coins);
    cout << result << endl;

}