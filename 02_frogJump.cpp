#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ll long long
#define MOD 1000000007
#define F first
#define S second
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int gcd(int a,int b){if(b==0)return a;else return gcd(b,a%b);}
int lcm(int a,int b){return a*b/gcd(a,b);}



/**
 *  Top down approach using 1D DP
 *  TC O(N);
 *  SC O(N) + callstack;
 */

// vector<int> dp;
// int f(vector<int>& height, int idx){
//     if(dp[idx] != -1) return dp[idx];
//     if(idx <= 0) return 0;
//     if(idx == 1) return abs(height[idx] - height[idx-1]);
//     int oneJump = abs(height[idx] - height[idx-1]) + f(height, idx-1);
//     int twoJump = abs(height[idx] - height[idx-2]) + f(height, idx-2);
//     return dp[idx] = min(oneJump, twoJump);
// }

/**
 *  Bottom up approach using 1D DP
 *  TC O(N);
 *  SC o(N);
 */

// int f2(vector<int>& height){
//     vector<int> dp(height.size());
//     dp[0] = 0;
//     dp[1] = abs(height[0] - height[1]);
//     for(int idx = 2; idx < height.size(); idx++){
//         int oneJump = abs(height[idx] - height[idx-1]) + dp[idx-1];
//         int twoJump = abs(height[idx] - height[idx-2]) + dp[idx-2];
//         dp[idx] = min(oneJump, twoJump);
//     }
//     return dp[height.size()-1];
// }


/**
 *  Bottom up approach using 1D DP [SPACE OPTIMIZATION]
 *  TC O(N);
 *  SC o(1);
 */

int f3(vector<int>& height){
    int prev = 0;
    int curr = abs(height[0] - height[1]);
    for(int idx = 2; idx < height.size(); idx++){
        int oneJump = abs(height[idx] - height[idx-1]) + curr;
        int twoJump = abs(height[idx] - height[idx-2]) + prev;
        prev = curr;
        curr = min(oneJump, twoJump);
    }
    return curr;
}

void solve() {
    int n;
    cin>>n;
    vector<int> v;
    // dp.clear();
    // dp.resize(n+5, -1);
    for(int i = 0;i < n; i++){
        int ele;
        cin>>ele;
        v.emplace_back(ele);
    }
    // cout<<f(v, n-1);
    cout<<f3(v);

}


int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fast_io;
    int t = 1;
    //cin>>t;
    while(t--) solve();
    return 0;
}