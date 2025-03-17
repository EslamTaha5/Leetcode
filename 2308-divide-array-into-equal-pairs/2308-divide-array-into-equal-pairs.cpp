class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int freq[501]{};
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(freq[nums[i]])cnt--;
            else cnt++;
            freq[nums[i]] ^= 1;
        }
        return cnt == 0;
    }
};