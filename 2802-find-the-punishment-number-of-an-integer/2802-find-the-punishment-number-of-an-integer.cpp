class Solution {
public:
    int solve(int i , int num,const string &s, vector<vector<int>>& dp){
        if(num < 0) return 0;
        if(i == s.size()){
            return num == 0;
        }
        int &ret = dp[i][num];
        if(~ret) return ret;
        ret = 0;
        int val = 0;
        for(int j = i; j < s.size(); j++){
            val = val * 10 + (s[j] - '0');
            ret |= solve(j + 1, num - val, s, dp);
        }
        return ret;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int x = i * i;
            string s = to_string(x);
            vector<vector<int>> dp(s.size() + 1, vector<int>(i + 2, -1));
            if(solve(0, i, s, dp))ans += x;
        }
        return ans;
    }
};