class Solution {
public:
    int minimumRecolors(string s, int k) {
        int ans = 200, w = 0, b = 0;
        for(int i = 0; i < k; i++){
            if(s[i] == 'W')w++;
            else b++;
        }
        ans = w;
        for(int i = k; i < s.size(); i++){
            if(s[i - k] == 'W')w--;
            else b--;
            if(s[i] == 'W')w++;
            else b++;
            ans = min(ans, w);

        }
        return ans;
    }
};