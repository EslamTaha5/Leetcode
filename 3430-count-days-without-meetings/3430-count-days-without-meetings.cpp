class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int ans = meetings[0][0] - 1;
        
        int l = -1, r = meetings[0][1];
        for(auto& it: meetings){
            if(l == -1 || it[0] > r){
                if(l != -1)ans += it[0] - r - 1;

                l = it[0];
                r = it[1];
            }else{
                r = max(r, it[1]);
            }
        }
        ans += days - r;
    
        return ans;
    }
};