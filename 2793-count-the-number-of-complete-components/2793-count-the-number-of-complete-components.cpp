class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 2), adj_mat(n + 2, vector<int>(n + 2));
        for(auto& it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            adj_mat[it[0]][it[1]] = adj_mat[it[1]][it[0]] = 1;
        }
        int ans = 0;
        vector<bool> vis(n + 2);
        vector<int> path;
        function <void(int)> dfs = [&](int i)->void{
            if(vis[i]) return;
            path.push_back(i);
            vis[i] = 1;
            for(auto& it: adj[i]){
                dfs(it);
            }
        };
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                path.clear();
                dfs(i);
                bool f = 1;
                for(auto& it: path){
                    for(auto &it2: path){
                        if(it == it2) continue;
                        f &= adj_mat[it][it2];
                    }
                }
                ans += f;
            }
        }
        return ans;
    }
};