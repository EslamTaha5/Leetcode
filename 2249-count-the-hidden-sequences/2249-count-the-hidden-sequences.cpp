class Solution {
public:
    int numberOfArrays(vector<int>& v, int lower, int upper) {
        int n = v.size();
        long long sum = 0, mx = 0, mn = 0;
        for(int i = 0; i < n; i++){
            sum += v[i];
            mx = max(mx, sum);
            mn = min(mn, sum);
        }
        return max(0LL, upper - lower + 1 - (mx - mn));
    }
};