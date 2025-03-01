class Solution {
public:
    vector<int> applyOperations(vector<int>& v) {
        int n = v.size();
        vector<int> tmp;
        for(int i = 0; i < n - 1; i++){
            if(v[i] == v[i + 1]){
                v[i] *= 2;
                v[i + 1] = 0;
            }
        }
        for(auto& it: v){
            if(it) tmp.push_back(it);
        }
        for(auto& it: v){
            if(!it) tmp.push_back(it);
        }
        return tmp;
    }
};