class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> v(1000005, 1);
        v[0] = v[1] = 0;
        vector<int> p;
        for(int i =2; i < 1000005; i++){
            if(!v[i]) continue;
            p.push_back(i);
            for(int j = i + i; j < 1000005; j+= i){
                v[j] = 0;
            }
        }
        auto it = lower_bound(p.begin(), p.end(), left) - p.begin();
        it++;
        vector<int> ans{-1, -1};
        int diff = 1e9;
        while(it < p.size() && p[it] <= right){
           // cout << left << " " << p[it] << endl;
            if(it){
                if(p[it] - p[it - 1] < diff){
                    ans = {p[it - 1], p[it]};
                    diff = ans[1] - ans[0];
                }
            }
            it++;
        }
        return ans;


    }
};