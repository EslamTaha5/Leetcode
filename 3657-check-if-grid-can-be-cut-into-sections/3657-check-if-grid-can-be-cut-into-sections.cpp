class Solution {
public:
    int check(vector<pair<int, int>> &v){
        sort(v.begin(), v.end());
        int cnt = 0, ans = 0;
        for(int i = 0; i < v.size(); i++){
            cnt += v[i].second;
            ans += (cnt == 0);
        }
        return ans;
    }
    bool checkValidCuts(int n, vector<vector<int>>& v) {
        vector<pair<int, int>> x, y;
        int m = v.size();
        for(int i = 0; i <m; i++){
            x.push_back({v[i][0], 1});
            x.push_back({v[i][2], -1});
            y.push_back({v[i][1], 1});
            y.push_back({v[i][3], -1});
        }
        return max(check(x), check(y)) >= 3;
    }
};