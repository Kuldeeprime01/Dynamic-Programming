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
 * Top down approach 1D DP
 * TC : O(N)
 * SC : O(N) + callstack
 */



vector<int> dp;
int f(vector<int>& nums, int idx){
    if(idx == 1) return max(nums[0], nums[1]);
    else if(idx == 0) return nums[0];

    if(dp[idx] != -1) return dp[idx];
    int money = 0;
    // if looted
    money = max(money, f(nums, idx-2) + nums[idx]);
    // if not looted
    money = max(money, f(nums, idx-1));
    return dp[idx] = money;
}

/**
 * Top Bottom up approach 1D DP
 * TC : O(N)
 * SC : O(N)
 */

int f2(vector<int>&nums){
    dp.clear();
    dp.resize(nums.size(), 0);
    if(nums.size() >= 2) dp[1] = max(nums[0], nums[1]);
    dp[0] = nums[0];
    for(int idx = 2; idx < nums.size() ; idx++){
        dp[idx] = max(dp[idx-2]+nums[idx], dp[idx-1]+0);
    }
    return dp[nums.size()-1];
}

/**
 * Top Bottom up approach 1D DP [SPACE OPTIMIZATION]
 * TC : O(N)
 * SC : O(1)
 */


int f3(vector<int>& nums){
    int prev = nums[0];
    if(nums.size() == 1) return nums[0];
    int curr = max(nums[0], nums[1]);
    for(int idx = 2; idx < nums.size(); idx++){
        int next = max(prev+nums[idx], curr+0);
        prev = curr;
        curr = next;
    }
    return curr;
}
int rob(vector<int>& nums) {
    // dp.clear();
    // dp.resize(nums.size(), -1);
    // return f(nums, nums.size()-1);
    return f3(nums);
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