class Solution {
public:
    int dp[1001][1001], n;
    vector<int> ans;
    int solve(int i, int lst, vector<int> &v){
        if(i == n) return 0;
        int &ret = dp[i][lst];
        if(~ret) return ret;
        ret = solve(i + 1, lst, v);
        if(lst == n || v[i] % v[lst] == 0 || v[lst] % v[i] == 0){
            ret = max(ret, solve(i + 1, i, v) + 1);
        }
        return ret;
    }
    void build(int i, int lst, vector<int> &v){
        if(i == n) return;
        int best = solve(i, lst, v);
        if(solve(i + 1, lst, v) == best){
            build(i + 1, lst, v);
            return;
        }
        ans.push_back(v[i]);
        build(i + 1, i, v);
    }
    vector<int> largestDivisibleSubset(vector<int>& v) {
       
        sort(v.begin(), v.end());
        n = v.size();
        memset(dp, -1, sizeof dp);
        int ret = solve(0, n, v);
       // cout << ret << endl;
        build(0, n, v);
        return ans;
    }
};