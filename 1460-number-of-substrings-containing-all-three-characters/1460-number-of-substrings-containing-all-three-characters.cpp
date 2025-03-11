class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        vector<int> v{-1, -1, -1};
        for(int i = 0; i < s.size(); i++){
            v[s[i] - 'a'] = i;
            ans += 1 + *min_element(v.begin(), v.end());
        }
        return ans;
    }
};