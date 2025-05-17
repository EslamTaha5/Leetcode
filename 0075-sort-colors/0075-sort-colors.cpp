class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3]{};
        for(auto& it: nums){
            cnt[it]++;
        }
        for(int i = 0, j = 0; i < 3; i++){
            while(cnt[i]--){
                nums[j] = i;
                j++;
            }
        }
    }
};