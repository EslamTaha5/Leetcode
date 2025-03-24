class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<pair<int, int>> v;
        int l = 0;
        for(auto& it: meetings){
            if(v.empty() || it[0] > v.back().second){
                v.push_back({it[0], it[1]});
            }else{
                v.back().second = max(it[1], v.back().second);
            }
        }
    
        int ans = days - v.back().second + v.front().first - 1;
        for(int i = 1; i < v.size(); i++){
            ans += v[i].first - v[i - 1].second - 1;
        }
        return ans;
    }
};