class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> freq(n * n + 2);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                freq[grid[i][j]]++;
            }
        }
        vector<int> ans;
        for(int i = 1; i <= n * n; i++){
            if(freq[i] == 2 || freq[i] == 0){
                ans.push_back(i);
            }
        }
        if(freq[ans[0]] == 0) swap(ans[0], ans[1]);
        return ans;
    }
};