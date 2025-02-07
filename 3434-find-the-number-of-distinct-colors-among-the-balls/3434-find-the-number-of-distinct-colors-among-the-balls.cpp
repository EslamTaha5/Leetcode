class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& v) {
        vector<int> ans(v.size());
        unordered_map<int, int> mp;
        unordered_map<int, int> freq;
        int id = 0;
        for(auto& it: v){
            int x = it[0];
            if(mp.find(x) != mp.end()){
                int col = mp[x];
                freq[col]--;
                if(!freq[col]) freq.erase(col);
            }
            freq[it[1]]++;
            mp[x] = it[1];
            ans[id] = freq.size();
            id++;
        }
        return ans;
    }
};