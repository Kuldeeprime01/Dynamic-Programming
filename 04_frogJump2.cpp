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
 * Top down approach 1D [DP]
 * TC : O(N);
 * SC : O(N) + callstack;
 */

vector<int> dp;
int f(vector<int>& h, int k, int idx){
    if(idx <= 0) return 0;
    int ans = INT_MAX;
    if(dp[idx] != -1) return dp[idx];
    for(int i = 1; i <= k; i++){
        if(idx - i >= 0)
            ans = min(ans, abs(h[idx]-h[idx-i]) + f(h, k, idx-i));
    }
    return dp[idx] = ans;
}


/**
 * Bottom up approach
 * TC : O(N);
 * SC : O(N);
 */

int f2(vector<int>&h , int k){
    int n = h.size();
    dp.clear();
    dp.resize(n,0);
    for(int idx = 1; idx < n; idx++){
        int ans = INT_MAX;
        for(int i = 1; i <= k; i++){
            if(idx - i >= 0) ans = min(ans, abs(h[idx]-h[idx-i]) + f(h, k, idx-i));
        }
        dp[idx] = ans;
    }
    return dp[n-1];
}


void solve() {
    int n,k;
    cin>>n>>k;
    vector<int>h;
    dp.clear();
    dp.resize(n,-1);
    for(int i = 0;i < n; i++){
        int ele;
        cin>>ele;
        h.push_back(ele);
    }
    // cout<<f(h,k,h.size()-1);
    cout<<f2(h,k);
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
