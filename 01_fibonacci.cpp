// calculates the fibonacci of nth number


#include <bits/stdc++.h>
using namespace std;


/**
 *     Top Down approach using vector [1D] DP
 *     TC : o(n)
 *     SC : O(n) + callstack [reccursion]
 */

int f(int n, vector<int> dp){
    if(n == 1 || n == 2) return 1;     // base cases
    else if(n == 0) return 0;          // base cases
    if(dp[n] != -1) return dp[n];      // already computed 
    return dp[n] = f(n-1, dp) + f(n-2, dp);     // reccurance relation
}


/**
 *     Bottom up approach using vector [1D] DP
 *     TC : O(N);
 *     SC : O(N);
 */

int f1(int n, vector<int> dp){
    dp.assign(n+1,0); // reassing the dp array
    dp[0] = 0;
    dp[1] = 1; // adding base cases

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

/**
 *      Bottom Up approach with SPACE OPTIMIZATION
 *      TC : O(N);
 *      SC : O(1);
 */


int f3(int n){
    if(n == 0 || n == 1) return n;
    int prev = 0;
    int curr = 1;
    int next;
    for(int i = 2; i <= n ; i++){
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}


void solve() {
    int n = 9;
    vector<int> dp(n+1,-1);
    // cout<<f(n, dp);
    // cout<<f1(n, dp);
    cout<<f3(n);
}

int main()
{
    int t = 1;
    //cin>>t;
    while(t--) solve();
    return 0;
}