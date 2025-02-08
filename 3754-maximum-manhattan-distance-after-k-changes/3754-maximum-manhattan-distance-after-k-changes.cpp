class Solution {
public:
    int maxDistance(string ss, int k) {
        int n, w, s, e;
        n = w = s = e = 0;
        int ans = 0, x = 0, y = 0;;
        for(auto& it: ss){
            if(it == 'N')n++;
            else if(it == 'W')w++;
            else if(it == 'S')s++;
            else e++;
            
            int val = min({s, k, n});
            int val2 = min({w, k - val, e});
            if(e > w)x = e - ( w - val2);
            else x = w - (e - val2);
            if(n > s) y = n - (s - val);
            else y = s - (n - val);
            
            ans = max(ans, abs(x) + abs(y) + val + val2);
            
        }
        return ans;
    }
};