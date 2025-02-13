class Solution {
public:
#define ll long long
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll> pq;
        int ans = 0;
        for(auto& it: nums) pq.push(-it);
        while(-pq.top() < k){
            ll x = -pq.top();
            pq.pop();
            ll y = -pq.top();
            pq.pop();
            pq.push(-(2 * x + y));
            ans++;
        }
        return ans;
    }
};