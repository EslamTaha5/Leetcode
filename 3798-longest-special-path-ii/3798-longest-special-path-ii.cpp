class Solution {
public:
    vector<vector<pair<int, int> > > adj;
    vector<int> len;
    vector<int> path;
    vector<int> freq;
    int cnt = 0, idx = 0, twice = 0;
    vector<int> res{0, 0};
    vector<vector<int> > occ;


    void dfs(int i, int par, vector<int> &v) {
        path.push_back(i);
        freq[v[i]]++;
        occ[v[i]].push_back(path.size() - 1);
        int old_twice = twice, old_idx = idx, old_cnt = cnt;
        if (freq[v[i]] >= 2) {
            if (cnt == 0) {
                twice = occ[v[i]][occ[v[i]].size() - 2];
            }
            cnt++;
        }
        if (cnt == 2) {
            int tmp = occ[v[i]][occ[v[i]].size() - 2];
            if (tmp > twice) swap(tmp, twice);
            idx = max(tmp + 1, idx);
            cnt = 1;
        }

        if (occ[v[i]].size() >= 3) {
            idx = max(idx,1 + occ[v[i]][occ[v[i]].size() - 3]);
            twice = max(twice, occ[v[i]][occ[v[i]].size() - 2]);
        }
        int sum = 0;
        if (len.size())sum = len.back();
        if (idx) sum -= len[idx - 1];

        if (sum > res[0]) {
            res[0] = sum;
            res[1] = path.size() - idx;
        }else if(sum == res[0] && res[1] > path.size() - idx){
            res[1] = path.size() - idx;
        }

        for (auto &it: adj[i]) {
            if (it.first == par) continue;
            if (len.size()) len.push_back(it.second + len.back());
            else len.push_back(it.second);

            dfs(it.first, i, v);
            len.pop_back();
        }
        twice = old_twice;
        idx = old_idx;
        cnt = old_cnt;
        path.pop_back();
        occ[v[i]].pop_back();
        freq[v[i]]--;
    }

    vector<int> longestSpecialPath(vector<vector<int> > &edges, vector<int> &nums) {
        int n = nums.size();
        adj = vector<vector<pair<int, int> > >(n);
        for (auto &it: edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        occ = vector<vector<int> >(100008);
        freq = vector<int>(100008, 0);
        dfs(0, -1, nums);
        return res;
    }
};
const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
