class Solution {
public:
#define ll long long
    ll dp[60000][1 << 5], n = 0, m = 0;
    ll solve(int i, int j, vector<int> &nums, vector<int> &target) {
        if (j == (1 << m) - 1) return 0;
        if (i == n) return 1e6;
        ll &ret = dp[i][j];
        if (~ret) return ret;
        ret = 1e8;
        for (int k = 0; k < (1 << m); k++) {
            ll val = 1;
            for (int l = 0; l < m; l++) {
                if (k >> l & 1) {
                    val = lcm(val, target[l]);
                }
            }
            ll rem = nums[i] % val;
            if (!rem) rem = val;
            ll cost = val - rem;
            ret = min(ret, cost + solve(i + 1, j | k, nums, target));
        }
        return ret;
    }
    

    int minimumIncrements(vector<int> &nums, vector<int> &target) {
        n = nums.size();
        m = target.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, nums, target);
    }
};
