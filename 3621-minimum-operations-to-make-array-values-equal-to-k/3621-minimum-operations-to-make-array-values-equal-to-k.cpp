class Solution {
public:
    int minOperations(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        if(v[0] < k) return -1;
        if(v[0] == k) return v.size() - 1;
        return v.size();
    }
};