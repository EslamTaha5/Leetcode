class Solution {
public:
    int dp[1001][1001];
    int solve(int i, int j, string &s, string &t){
        if(i == s.size() || j == t.size()) return 0;
        int &ret = dp[i][j];
        if(~ret) return ret;
        ret = solve(i + 1, j, s, t);
        ret = max(ret, solve(i, j + 1, s, t));
        if(s[i] == t[j]){
            ret = max(ret, 1 + solve(i + 1, j + 1, s, t));
        }
        return ret;
    }
    string lcs_str;
    void build(int i, int j, string & s, string &t){
        if(i == s.size() || j == t.size()) return;
        int best = solve(i, j, s, t);
        if(s[i] == t[j] && solve(i + 1, j + 1, s, t) + 1 == best){
            lcs_str += s[i];
            build(i + 1, j + 1, s, t);
            return;
        }
        if(solve(i + 1, j, s, t) == best){
            build(i + 1, j, s, t);
            return;
        }
    

        build(i, j + 1, s, t);
    }
    string shortestCommonSupersequence(string str1, string str2) {
        memset(dp, -1, sizeof dp);
        int lcs = solve(0, 0, str1, str2);
        build(0, 0, str1, str2);
        int id1 = 0, id2 = 0;
        string ans;
        for(int i = 0; i < lcs_str.size(); i++){
            while(id1 < str1.size() && lcs_str[i] != str1[id1]){
                ans += str1[id1];
                id1++;
            }
            while(id2 < str2.size() && lcs_str[i] != str2[id2]){
                ans += str2[id2];
                id2++;
            }
            id1++, id2++;
            ans += lcs_str[i];
        }
        while(id1 < str1.size()){
            ans += str1[id1++];
        }
        while(id2 < str2.size()){
            ans += str2[id2++];
        }
        return ans;
    }
};