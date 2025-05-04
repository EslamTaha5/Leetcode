class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& v) {
        int arr[10][10]{};
        int ans = 0;
        for(auto& it: v){
            if(it[0] > it[1]) swap(it[0], it[1]);
            ans += arr[it[0]][it[1]];
            arr[it[0]][it[1]]++;
        }
        return ans;
    }
};