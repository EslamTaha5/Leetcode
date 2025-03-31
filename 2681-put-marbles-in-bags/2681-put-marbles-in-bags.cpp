class Solution {
public:
    long long putMarbles(vector<int>& v, int k) {
        int n = v.size();
        vector<int> pref;
        long long a = v[0] + v[n - 1];
        long long b = a;
        for(int i = 1; i < n; i++){
            pref.push_back(v[i] + v[i - 1]);
        }
        sort(pref.begin(), pref.end());
        for(int i = 0; i < k - 1; i++){
            a += pref[i];
            b += pref[n - i - 2];
        }
        return b - a;
    }
};