class Solution {
public:
#define ll long long
#define F first
#define S second
    const int mod = 1e9 + 7;
    struct Node {
        ll node, cost, ways, mn_flight, mx_flight;
    
        Node() {
            cost = 10000000000000;
            ways = 0;
            mn_flight = 0;
            mx_flight = 0;
            node = 0;
        }
    
        Node(ll node, ll cost, ll ways, ll mn_flight, ll mx_flight)
            : node(node), cost(cost), ways(ways), mn_flight(mn_flight), mx_flight(mx_flight) {
        }
    
        bool operator<(const Node &other) const {
            if (cost != other.cost) {
    
            return cost > other.cost;
            }
            return ways < other.ways;
        }
    };

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
            priority_queue<array<ll, 2>> pq;
        vector<ll> dist(n + 2, 100000000000000), mx(n + 2), mn(n + 2), cnt(n + 2);
        dist[0] = 0;
        cnt[0] = 1;
        pq.push({0, 0});
        vector<int> vis(n + 2);
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            if (vis[p[1]])continue;
            vis[p[1]] = 1;
            for (auto &it: adj[p[1]]) {
                ll new_cost = (-p[0]) + it.S;
                if (new_cost < dist[it.F]) {
                    cnt[it.F] = cnt[p[1]];
                    mn[it.F] = mn[p[1]] + 1;
                    mx[it.F] = mx[p[1]] + 1;
                    dist[it.F] = new_cost;
                    pq.push({-new_cost, it.F});
                } else if (new_cost == dist[it.F]) {
                    (cnt[it.F] += cnt[p[1]]) %= mod;
                    mn[it.F] = min(mn[it.F], mn[p[1]] + 1);
                    mx[it.F] = max(mx[p[1]] + 1, mx[it.F]);
                }
            }
        }

        return cnt[n - 1];

    }
};