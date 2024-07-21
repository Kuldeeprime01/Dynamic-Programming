/**
 *           https://leetcode.com/problems/climbing-stairs/description/
 */


#include <bits/stdc++.h>
using namespace std;

/**
 *  Top Down approach using [1D] Dp vector
 *  TC : O(N);
 *  SC : O(N) + callStack [recursion]
 */

int f(int n, vector<int>&dp){
    if(n == 0 || n == 1) return 1; // base cases
    if(dp[n] != -1) return dp[n]; // already calculated state
    return dp[n] =  f(n-2, dp) + f(n-1, dp); // recurance relation
}

/**
 *  Bottom up approach using [1D] Dp vector
 *  TC : O(N);
 *  SC : O(N);
 */

int f1(int n, vector<int>&dp){
    dp.assign(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-2] + dp[i-1];
    }
    return dp[n];
}

/**
 *  Bottom up approach [SPACE OPTIMIZATION]
 *  TC : O(N);
 *  SC : O(N) + callStack [recursion]
 */

int f2(int n){
    int prev = 1;
    int curr = 1;
    for(int i = 2; i <= n; i++){
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

int climbStairs(int n) {
    // vector<int> dp(n+1, -1);
    return f2(n);
}

void solve() {
    int n = 45;
    cout<<climbStairs(n);
}

int main()
{
    int t = 1;
    //cin>>t;
    while(t--) solve();
    return 0;
}