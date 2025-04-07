class Solution {
public:
    bool canPartition(vector<int>& v) {
        int sum = 0, n = v.size();
        for(auto& it: v) sum += it;
        if(sum & 1) return 0;
        vector<int> dp(sum + 1);
        dp[sum / 2] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= sum / 2; j++){
                if(v[i] + j > sum / 2) break;
                dp[j] = dp[j] | dp[j + v[i]];
            }
        }
        return dp[0];
    }
};