class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int mx1[100]{}, mx2[100]{}, freq[100]{};
        int ans = -1, num, sum;
        for(int i = 0; i < nums.size(); i++){
            num = nums[i], sum = 0;
            while(num){
                sum += num % 10;
                num /= 10;
            }
            if(nums[i] > mx1[sum]){
                mx2[sum] = mx1[sum];
                mx1[sum] = nums[i];
            }else if(nums[i] > mx2[sum]){
                mx2[sum] = nums[i];
            }
            freq[sum]++;
            if(freq[sum] > 1) ans = max(ans, mx1[sum] + mx2[sum]);
        }
        return ans;
    }
};