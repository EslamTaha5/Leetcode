class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> mx1(100, -1), mx2(100, -1), freq(100);
        int ans = -1;
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i], y = 0;
            while(x){
                y += x % 10;
                x /= 10;
            }
            if(nums[i] > mx1[y]){
                mx2[y] = mx1[y];
                mx1[y] = nums[i];
            }else if(nums[i] > mx2[y]){
                mx2[y] = nums[i];
            }
            freq[y]++;
            if(freq[y] > 1) ans = max(ans, mx1[y] + mx2[y]);
        }
        return ans;
    }
};