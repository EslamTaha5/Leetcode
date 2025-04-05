class Solution {
public:
    int subsetXORSum(vector<int>& v) {
        int ans = 0, n = v.size();
        function <int(int, int)> solve = [&](int i, int x)->int{
            if(i == n) return x;
            return solve(i + 1, x) + solve(i + 1, x ^ v[i]);
        };
        return solve(0, 0);
    }
};