class Solution {
public:
    
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto& it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<int> component(n + 2, -1), ans(n + 5);
        int id = 0, sum = INT_MAX;
        function <void(int)> dfs = [&](int i)->void{
            if(component[i]!=-1) return;

            component[i] = id;
            for(auto& it: adj[i]){
                sum &= it.second;
                dfs(it.first);
            }
        };
        for(int i = 0; i < n; i++){
            if(~component[i]) continue;
            sum = INT_MAX;
            id++;
            dfs(i);
            ans[id] = sum;
        }
        vector<int> ret;
        for(auto& it: query){
            if(component[it[0]] != component[it[1]]){
                ret.push_back(-1);
            }else{
                ret.push_back(ans[component[it[0]]]);
            }
        }
        return ret;
    }
};