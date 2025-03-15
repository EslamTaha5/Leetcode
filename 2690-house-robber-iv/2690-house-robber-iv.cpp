class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        auto valid = [&](int mid){
            int cnt = 0;
            bool f = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] <= mid){
                    if(!f){
                        cnt++;
                        f = 1;
                        continue;
                    }
                }
                f = 0;
            }
            return cnt >= k;
        };
        int l = 1, r = 1e9 + 10, mid, ans;
        while(l <= r){
            mid = l + r >> 1;
            if(valid(mid)){
                r = mid - 1;
                ans = mid;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};