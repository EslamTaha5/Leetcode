class Solution {
public:
#define ll long long
    long long countGood(vector<int>& v, int k) {
        ll ret = 0, cnt = 0, n = v.size();
        map<int, int>mp;
        for(int i = 0, j = 0; i < n; i++){
            cnt += mp[v[i]];
            mp[v[i]]++;
            while(cnt >= k){
                mp[v[j]]--;
                cnt -= mp[v[j]];
                j++;
            }
            ret += i - j;
        }
        return n * (n - 1) / 2 - ret;
    }
};