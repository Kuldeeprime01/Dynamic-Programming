//   https://leetcode.com/problems/unique-paths/


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
 * Top down approach using 2D DP
 * TC : O(M*N)
 * SC : O(M*N) + callstack
 */

vector<vector<int>> dp;
int f(int m, int n){
    if(m == 0 && n == 0) return 1; // base cases;
    if(m < 0 || n < 0) return 0;
    if(dp[m][n] != -1) return dp[m][n];
    int ans = 0;
    ans += f(m-1,n);
    ans += f(m, n-1);
    return dp[m][n] = ans;
}

/**
 * Bottom up approach using 2D DP
 * TC : O(M*N)
 * SC : O(M*N)
 */

int f2(int m ,int n){
    vector<vector<int>>dp(m , vector<int>(n, 0));
    dp[0][0] = 1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0) continue;
            int ans = 0;
            if(i != 0) ans += dp[i-1][j];
            if(j != 0) ans += dp[i][j-1];
            dp[i][j] = ans;
        }
    }
    return dp[m-1][n-1];
}

/**
 * Bottom up approach using 2D DP [SPACE OPTIMIZATION]
 * TC : O(M*N)
 * SC : O(N)
 */

int f3(int m, int n){
    vector<int> prev(n, 1);
    for(int i = 1; i < m; i++){
        vector<int> curr(n,0);
        for(int j = 0; j < n; j++){
            int ans = 0;
            if(j != 0) ans += curr[j-1];
            ans += prev[j];
            curr[j] = ans;
        }
        prev = curr;
    }
    return prev[n-1];
}
int uniquePaths(int m, int n) {
    dp.clear();
    dp.resize(m+1, vector<int>(n+1, -1));
    // return f(m-1,n-1);
    // return f2(m, n);
    return f3(m, n);

}

void solve() {
    
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