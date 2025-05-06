class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size(), x = 0, y = 0;
            x = (1 << 12) - 1;

        for(int i = 0; i < n; i++){
            y = nums[i] & x;
            nums[i] |= ((nums[y] & x) << 12);
        }
        for(auto& it: nums){
            it >>= 12;
        }
        return nums;
    }
};