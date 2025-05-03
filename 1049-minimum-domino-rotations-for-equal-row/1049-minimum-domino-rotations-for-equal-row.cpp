class Solution {
public:

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int ans = n + 10;
        for(int i = 1; i <= 6; i++){
            int x = 0, y = 0;
            for(int j = 0; j < n; j++){
                if(tops[j] != i && bottoms[j] != i){
                    x = y = n + 10;
                    break;
                }
                if(tops[j] != i)x++;
                if(bottoms[j] != i) y++; 
            }
            ans = min({ans, x, y});
        }
        return ans == n + 10 ? -1 : ans;
    }
};