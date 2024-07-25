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
 * Top Down approach 2d dp
 *  TC O(3n) == o(N);
 *  SC O(3n) + callstack
 */


vector<vector<int>> dp;
int f(vector<vector<int>>& v, int idx, int prev){
    if(idx < 0) return 0;
    if(dp[idx][prev] != -1) return dp[idx][prev];
    int ans = 0;
    for(int i = 0; i < 3; i++){
        if(i == prev) continue;
        ans = max(ans, v[idx][i] + f(v, idx-1, i));
    }
    return dp[idx][prev] =  ans;
}


/**
 * Bottom up approach 2D dp
 * TC O(n)
 * SC O(n)
 */

int f2(vector<vector<int>>&v){
    int n = v.size();
    vector<vector<int>> dp(n, vector<int> (3,0));
    for(int i = 0; i < 3; i++){
        dp[0][i] = v[0][i];
    }
    for(int idx = 1; idx < n; idx++){
        for(int i = 0; i < 3; i++){
            dp[idx][i] = max(dp[idx-1][(i+1)%3], dp[idx-1][(i+2)%3]) + v[idx][i];
        }
    }
    int ans = 0;
    for(int i = 0;i < 3; i++){
        ans = max(ans, dp[n-1][i]);
    }
    return ans;
}


/**
 * Bottom up approach 2D dp [SPACE OPTIMIZATION]
 * TC O(3n)
 * SC O(1)
 */

int f3(vector<vector<int>> &v){
    int n = v.size();
    vector<int> prev(3,0);
    for(int i = 0;i < 3; i++){
        prev[i] = v[0][i];
    }
    for(int idx = 1; idx < n; idx++){
        vector<int> curr(3,0);
        for(int i = 0; i < 3; i++){
            curr[i] = max(prev[(i+1)%3], prev[(i+2)%3]) + v[idx][i];
        }
        prev = curr;
    }
    int ans = 0;
    for(int i = 0;i < 3; i++){
        ans = max(prev[i], ans);
    }
    return ans;
}
void solve() {
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n, vector<int>(4,-1));
    vector<vector<int>> v(n, vector<int>(3));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin>>v[i][j];
        }
    }
    // cout<<f(v,n-1, 3);
    // cout<<f2(v);
    cout<<f3(v);
}

int32_t main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    fast_io;
    int t = 1;
    //cin>>t;
    while(t--) solve();
    return 0;
}