#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

class Solution {
public:
#define ll long long
    long long goodTriplets(vector<int>& a, vector<int>& b) {
        map<int, int> mp;
        ordered_set st;
        for(int i = 0; i < a.size(); i++){
            mp[a[i]] = i;
        }
        ll ans = 0, n = a.size(), m = b.size();
        for(int i = 0; i < m; i++){
            int idx = mp[b[i]];
            int x  = st.order_of_key(idx);
            int y = n - idx - 1 - (st.size() - x);
            ans += 1LL * x * y;
            st.insert(idx);
        }
        return ans;

    }
};