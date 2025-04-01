class Solution {
public:
#define ll long long
    long long mostPoints(vector<vector<int>>& v) {
        int n = v.size();
        vector<ll> dp(n);
        for(int i = n - 1; i >= 0; i--){
            int idx = i + v[i][1] + 1;
            dp[i] = v[i][0];
            if(idx < n){
                dp[i] = dp[idx] + v[i][0];
            }
            if(i < n - 1){
                dp[i] = max(dp[i], dp[i + 1]);
            }
        }
        return dp[0];
    }
};