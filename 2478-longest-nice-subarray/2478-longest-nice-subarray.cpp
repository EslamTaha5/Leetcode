class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int freq[40]{};
        int ans = 0;
        auto check = [&]()->bool{
            for(int k = 0; k < 30 ;k++){
                if(freq[k] > 1){
                    return true;     
                }
            }
            return false;
        };
        auto add = [&](int x,int sign){
            for(int i = 0; i < 30 ; i++){
                if(x >> i & 1){
                    freq[i] += sign;
                }
            }
        };
        for(int i = 0, j = 0; i < nums.size(); i++){
            add(nums[i], 1);
            bool f= 1;
            while(f){
                f = check();
                if(f){
                    add(nums[j], -1);
                    j++;
                }
            }
            
            ans = max(ans, i - j + 1);

        }
        return ans;
    }
};