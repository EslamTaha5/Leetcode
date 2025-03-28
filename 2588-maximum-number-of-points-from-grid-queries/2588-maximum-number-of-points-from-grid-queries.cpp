class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size(), m = grid[0].size(), q = queries.size();
        vector<pair<int, int>> qu;
        for(int i = 0; i < q; i++){
            qu.push_back({queries[i], i});
        }
        sort(qu.begin(), qu.end());
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        vector<vector<int>> vis(n, vector<int>(m + 1));
        pq.push({grid[0][0], 0, 0});
        vis[0][0] = 1;
        int cnt  =0;
        vector<int> ans(q);
        for(auto& [i, j] : qu){
            while(!pq.empty() && pq.top()[0] < i){
                auto p = pq.top();
                pq.pop();
                cnt++;
                for(auto& dx: {0, 1, -1}){
                    for(auto& dy: {0, 1, -1}){
                        if(abs(dx) + abs(dy)  != 1) continue;
                        int nx = dx + p[1];
                        int ny = dy + p[2];
                        if(ny >= 0 && nx >= 0 && nx < n && ny < m && !vis[nx][ny]){
                            vis[nx][ny] = 1;
                            pq.push({grid[nx][ny], nx, ny});
                        }
                    }
                }
            }
            ans[j] = cnt;
        }
        return ans;

    }
};