class Solution {
public:
    int subsetXORSum(vector<int>& v) {
        int ans = 0, n = v.size();
        for(int i = 0 ; i < 1 << n; i++){
            int x = 0;
            for(int j = 0; j < n; j++){
                if(i >> j & 1){
                    x ^= v[j];
                }
            }
            ans += x;
        }
        return ans;
    }
};