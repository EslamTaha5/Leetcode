const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int ans = meetings[0][0] - 1;
        
        int r = -1;
        for(auto& it: meetings){
            if(r == -1 || it[0] > r){
                if(r != -1)ans += it[0] - r - 1;
                r = it[1];
            }else{
                r = max(r, it[1]);
            }
        }
        ans += days - r;
    
        return ans;
    }
};