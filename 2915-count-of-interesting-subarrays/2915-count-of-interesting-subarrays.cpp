class Solution {
public:
#define ll long long
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        map<int, int> mp;
        ll cnt = 0, ans  = 0;
        mp[0] = 1;
        for(auto& it: nums){
            if(it % modulo == k) cnt++;
            ll x = cnt % modulo;
            ll y = (x - k + modulo) % modulo;
            ans += mp[y];
            mp[x]++;
        }
        return ans;
    }
};