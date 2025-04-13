class Solution {
public:
    class SegmentTree {
    private:
        int tree[4 * 100000 + 10]{};
        int n;

    public:
        SegmentTree(int size) : n(size) {
        }

        void update(int idx, int val) {
            update(1, 1, n, idx, val);
        }

        int query(int l, int r) {
            if (l > r) return 0;
            return query(1, 1, n, l, r);
        }

    private:
        void update(int node, int start, int end, int idx, int val) {
            if (start == end) {
                tree[node] = val;
                return;
            }

            int mid = (start + end) / 2;
            if (idx <= mid)
                update(2 * node, start, mid, idx, val);
            else
                update(2 * node + 1, mid + 1, end, idx, val);

            tree[node] = tree[2 * node]+ tree[2 * node + 1];
        }

        int query(int node, int start, int end, int l, int r) {
            if (r < start || end < l)
                return 0;

            if (l <= start && end <= r){
                
                return tree[node];
            }

            int mid = (start + end) / 2;
            return
                query(2 * node, start, mid, l, r)+
                query(2 * node + 1, mid + 1, end, l, r)
            ;
        }
    };


    class HLD {
    private:
        int n, timer;
        int nodeId[100003], size[100003], top[100003], depth[100003], parent[100003];

        vector<int> graph[100003];
        SegmentTree segTree;

    public:
        HLD(int nodes) : n(nodes), timer(1), segTree(nodes) {
            for (int i = 1; i <= n; i++) {
                size[i] = 1;
            }
        }

        void addEdge(int u, int v) {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        void init(int root = 1) {
            dfs_size(root, 0);
            dfs_decompose(root, root);
        }

        void updateNode(int node, int val) {

            segTree.update(nodeId[node], val);
        }

        int queryPath(int u, int v) {
            int result = 0;
            while (top[u] != top[v]) {
                if (depth[top[u]] < depth[top[v]])
                    swap(u, v);

                int start = top[u];
                result +=segTree.query(nodeId[start], nodeId[u]);
                u = parent[start];
            }

            if (depth[u] > depth[v])
                swap(u, v);
            result += segTree.query(nodeId[u], nodeId[v]);
            return result;
        }

        int get_child(int x, int y) {
            if (parent[x] == y) return x;
            return y;
        }

    private:
        void dfs_size(int node, int par) {
            parent[node] = par;

            if (par)
                depth[node] = depth[par] + 1;

            for (auto &next: graph[node]) {
                if (next != par) {
                    dfs_size(next, node);
                    size[node] += size[next];
                    if (graph[node][0] == par || size[next] > size[graph[node][0]])
                        swap(graph[node][0], next);
                }
            }
        }


        void dfs_decompose(int node, int chain_top) {
            nodeId[node] = timer++;
            top[node] = chain_top;
            for (auto next: graph[node]) {
                if (next != parent[node]) {
                    if (next == graph[node][0])
                        dfs_decompose(next, chain_top);
                    else
                        dfs_decompose(next, next);
                }
            }
        }
    };

    vector<int> treeQueries(int n, vector<vector<int> > &edges, vector<vector<int> > &queries) {
        vector<int> ans;
        HLD hld(n);
        for (auto& it: edges) {
            hld.addEdge(it[0], it[1]);
        }
        hld.init();
        for (auto& it: edges) {
            int x = hld.get_child(it[0], it[1]);
            hld.updateNode(x, it[2]);
        }
        for (auto& it: queries) {
            if (it[0] == 1) {
                int u, v, x;
                u = it[1], v = it[2], x = it[3];
                int a = hld.get_child(u, v);
               // cout << u <<" " << v <<" "<<a <<" "<< x << endl;
                hld.updateNode(a, x);
            }else {
                int x = it[1];
                if(x == 1){
                    ans.push_back(0);
                }else 
                ans.push_back(hld.queryPath(1, x));
            }
        }
        return ans;

    }
};