class Solution {
public:
    int hamming[1001][1001], dp[1001][1011];
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        memset(hamming, 3, sizeof hamming);
        int n = words.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(words[i].size() != words[j].size() || groups[i] == groups[j]) continue;
                hamming[i][j] = 0;
                for(int k = 0; k < words[i].size(); k++){
                    if(words[i][k] != words[j][k]){
                        hamming[i][j]++;
                    }
                }
            }
        }

        memset(dp, -1, sizeof dp);
        function<int(int, int)> solve = [&](int i, int lst)->int{
            if(i == n) return 0;
            int &ret = dp[i][lst];
            if(~ret) return ret;
            ret = solve(i + 1, lst);
            if(lst < n){
                if(hamming[lst][i] == 1){
                    ret = max(ret, 1 + solve(i + 1, i));
                }
            }else{
                ret = max(ret, solve(i + 1, i) + 1);
            }
            return ret;
        };
        cout << solve(0, n + 2) << endl;
        vector<string> ans;
        function<void(int, int)> build = [&](int i, int lst)->void{
            if(i == n) return;
            int &best = dp[i][lst];
            int op1 = solve(i + 1, lst);
            int op2 = solve(i + 1, i) + 1;
            if(op1 == best){
                build(i + 1, lst);
            }else{
                ans.push_back(words[i]);
                build(i + 1, i);
            }
        };
        build(0, n + 2);
        return ans;
    }
};