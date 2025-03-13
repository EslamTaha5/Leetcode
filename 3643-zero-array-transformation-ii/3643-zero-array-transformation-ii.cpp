class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries)  {
        int n = nums.size(), q = queries.size();
        auto valid =[&](int mid)-> bool{
            vector<int>pref(n + 2);
            for(int i = 0; i < mid; i++){
                int l = queries[i][0];
                int r = queries[i][1];
                int val = queries[i][2];
                pref[l] += val;
                pref[r + 1] -= val;
            }

            for(int i = 0; i < n; i++){
               if(i)pref[i] += pref[i - 1];
               if(nums[i] > pref[i]) return false;
            }
            return true;
        };
        int l = 0, r = q, mid, ans = -1;
        while(l <= r){
            mid = (l + r) / 2;
            if(valid(mid)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }   
        return ans;
    }
};