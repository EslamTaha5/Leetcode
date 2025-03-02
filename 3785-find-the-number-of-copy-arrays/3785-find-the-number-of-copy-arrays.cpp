class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int l = bounds[0][0], r = bounds[0][1];
        for (int i = 1; i < bounds.size(); i++) {
            int difference = original[i] - original[i - 1];
            int new_l = l + difference;
            int new_r = r + difference;
            l = max(new_l, bounds[i][0]);
            r = min(new_r, bounds[i][1]);
        }
        return max(0, r - l + 1);
    }
};