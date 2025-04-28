class Solution {
public:
    long long countSubarrays(vector<int>& v, long long k) {
        long long ans = 0, len = 0, sum = 0, n = v.size();
        for(int i = 0, j = 0; i < n; i++){
            sum += v[i];
            len++;
            while(sum * len >= k){
                sum -= v[j];
                len--;
                j++;
            }
            ans += (i - j + 1);
        }
        return ans;
    }
};