class Solution {
public:
    int minimumOperations(vector<int>& v) {
        int n= v.size();
        int freq[101]{};
        for(int i = 0; i < n; i++){
            freq[v[i]]++;
        }
        int ans = 0;
        for(int i = 0, j = 0; i < n; j++){
            bool f = 0;
            for(int k = i; k < n; k++){
                if(freq[v[k]] > 1){
                    f = 1;
                    break;
                }
            }
            if(!f) break;
            ans++;
            for(int k = i; k < min(n, i + 3); k++){
                freq[v[k]]--;
            }
            i += 3;
        }
        return ans;
    }
};