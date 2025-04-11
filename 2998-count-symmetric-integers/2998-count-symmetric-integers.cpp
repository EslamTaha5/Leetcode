class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low; i <= high; i++){
            int lsum = 0, rsum = 0;
            int x = i, cnt = 0;
            while(x){
                cnt++;
                x /= 10;
            }
        
            if(cnt & 1) continue;
            x = i;
            int tcnt = cnt / 2;
            cnt /= 2;
            while(cnt--){
                lsum += x % 10;
                x/=10;
            }
            while(tcnt--){
                rsum += x %10;
                x /= 10;
            }
            if(lsum == rsum) ans++;
        }
        return ans;
    }
};