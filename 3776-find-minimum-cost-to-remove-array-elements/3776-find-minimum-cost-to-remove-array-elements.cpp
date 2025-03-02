class Solution {
public:
    int dp[1002][1002], n;
    int solve(int cur, int lst, vector<int>& v){

        if(cur + 1 >= n){
            if(cur < n){
                return max(v[lst], v[cur]);
            }
            return v[lst];
        }
        int &ret = dp[cur][lst];
        if(~ret) return ret;
        int mx = 0;
        
        mx = max(v[cur], v[cur + 1]);
        ret = solve(cur + 2, lst, v) + mx;

        mx = max(v[cur], v[lst]);
        ret = min(ret, solve(cur + 2, cur + 1, v) + mx);

        mx = max(v[cur + 1], v[lst]);
        ret = min(ret, solve(cur + 2, cur, v) + mx);
        return ret;
    }
    int minCost(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        if(nums.size() == 3){
            sort(nums.begin(), nums.end());
            return nums[2] + nums[0];
        }
        n = nums.size();
        memset(dp, -1, sizeof dp);
        int ans1 = solve(3, 0, nums) + max(nums[1], nums[2]);
        int ans2 = solve(3, 1, nums) + max(nums[0], nums[2]);
        int ans3 = solve(3, 2, nums) + max(nums[0], nums[1]);
        
        return min({ans1, ans2, ans3});

    }
};

const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();