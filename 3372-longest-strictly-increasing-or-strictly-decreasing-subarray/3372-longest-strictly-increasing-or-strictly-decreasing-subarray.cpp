class Solution {
public:
    int longestMonotonicSubarray(vector<int>& v) {
        int ans = 0, cnt = 0, lst = 0, lst2 = 55, cnt2 = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i] > lst)cnt++;
            else cnt = 1;
            if(v[i] < lst2)cnt2++;
            else cnt2 = 1;
            lst = v[i];
            lst2 = v[i];
            ans = max({ans, cnt, cnt2});
        }
        return ans;
    }
};