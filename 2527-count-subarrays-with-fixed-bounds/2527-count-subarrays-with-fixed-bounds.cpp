class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int l = 0, r = 0, n = nums.size();
        int idxl = -1, idxr = -1;
        while(r < n){
            if(nums[r] < minK || nums[r] > maxK){
                l = r + 1;
                r++;
                continue;
            }
            if(nums[r] == maxK) idxl = r;
            if(nums[r] == minK) idxr = r;
            ans += max(0, min(idxl, idxr) - l + 1);
            r++;
        }
        return ans;
    }
};