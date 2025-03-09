class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0, n = colors.size();
        int i = 0, j = 0, cnt = 1, lst = 0;
        while(i < n){
          //  cout << i << " " << j << " " << cnt << endl;
            if(i != j){
                if(colors[j] == colors[lst]){
                    if(j <= i) break;
                    cnt = 0;
                    i = j;
                }
                cnt++;
            }
            if(cnt == k){
                ans++;
                i++;
                cnt--;
            }
            lst = j;
            j++;
            j %= n;
        }
        return ans;
    }
};