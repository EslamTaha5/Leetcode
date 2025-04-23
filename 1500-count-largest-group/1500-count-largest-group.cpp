class Solution {
public:
    int countLargestGroup(int n) {
        int freq[100]{};
        int mx = 0, cnt =0;
        for(int i = 1; i <= n; i++){
            int x = i, y = 0;
            while(x){
                y += x % 10;
                x /= 10;
            }
            freq[y]++;
            if(freq[y] == mx){
                cnt++;
            }else if(freq[y] > mx){
                cnt = 1;
                mx = freq[y];
            }
        }
        return cnt;
    }
};