class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int ret = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int ret2 = (int)nums.size() - (upper_bound(nums.begin(), nums.end(), 0) - nums.begin());
        return max(ret, ret2);
    }
};