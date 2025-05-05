class Solution {
public:
#define ll long long
#define mod (int)(1e9 + 7)
    int numTilings(int n) {
        ll dp[1001]{};
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for(int i = 4; i <= n; i++){
            dp[i] = 0;
            dp[i] = 2 * dp[i - 1] % mod;
            (dp[i] += dp[i - 3]) %= mod;

        }
        return dp[n];
    }
};