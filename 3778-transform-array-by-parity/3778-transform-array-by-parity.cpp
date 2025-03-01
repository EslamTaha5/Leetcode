class Solution {
public:
    vector<int> transformArray(vector<int>& v) {
        for(auto& it: v){
            if(it & 1) it = 1;
            else it = 0;
        }
        sort(v.begin(), v.end());
        return v;
    }
};