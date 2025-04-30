class Solution {
public:
    int findNumbers(vector<int>& v) {
        int ans = 0;
        for(int i = 0; i < v.size(); i++){
            ans += (int) log10(v[i]) % 2;
        }
        return ans;
    }
};