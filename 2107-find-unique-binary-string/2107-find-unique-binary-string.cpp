class Solution {
public:
    map<string, int> mp;
    int n;
    string ans = "";
    void solve(string s){
        if(ans.size()) return ;
        if(s.size() == n){
            if(mp.find(s) == mp.end()){
                ans = s;
            
            }
            return;
        }
        s += "0";
        solve(s);
        s.pop_back();
        s += '1';
        solve(s);
        s.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) {
        for(auto& it: nums){
            mp[it] = 1;
        }
        n = nums[0].size();
        solve("");
        return ans;
    }

};