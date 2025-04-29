class Solution {
public:
#define ll long long
int mp[1000002];
    long long countSubarrays(vector<int>& v, int k) {
        ll ret = 0, n = v.size();
        int mx = *max_element(v.begin(), v.end());
        for(int i = 0, j = 0; i < n; i++){
            mp[v[i]]++;
            while(mp[mx] >= k){
                mp[v[j]]--;
                j++;
            }
            ret += i - j + 1;
        }
        cout << ret << " " << n << endl;
        return n * (n + 1) / 2 - ret;
    }
};