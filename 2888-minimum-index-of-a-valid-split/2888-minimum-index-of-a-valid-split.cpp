class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> pref, suff;
        for(auto& it: nums)suff[it]++;
        for(int i = 0; i < nums.size() - 1; i++){
            pref[nums[i]]++;
            suff[nums[i]]--;
            if(pref[nums[i]] * 2 > i + 1 &&
                suff[nums[i]] * 2 > nums.size() - i - 1) return i;
        }
        return -1;
    }
};