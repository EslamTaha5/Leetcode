class Solution {
public:
#define all(v) v.rbegin(), v.rend()
#define ll long long
#define mod 1000000007
    int factorize(int x) {
        int res = 0;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                res++;
                while (x % i == 0) {
                    x /= i;
                }
            }
        }
        if (x != 1) res++;
        return res;
    }

    long long fast_pow(ll x, ll n) {
        ll res = 1;
        while (n > 0) {
            if (n & 1) {
                (res *= x) %= mod;
            }
            x = x * x;
            n >>= 1;
            x = x % mod;
        }
        return res;
    }
    int maximumScore(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> pref(n), suff(n), factors(n);
        stack<int> sk;
        for (int i = 0; i < n; i++) {
            factors[i] = factorize(nums[i]);
        }

        for (int i = 0; i < n; i++) {
            while (!sk.empty() && factors[i] > factors[sk.top()]) {
                sk.pop();
            }
            pref[i] = sk.empty() ? -1 : sk.top();
            sk.push(i);
        }
        while (!sk.empty()) sk.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!sk.empty() && factors[i] >= factors[sk.top()]) sk.pop();
            suff[i] = sk.empty() ? n : sk.top();
            sk.push(i);
        }
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }
        sort(all(v));
        long long ans = 1;
        for (int i = 0; i < n && k > 0; i++) {
            auto [x, idx] = v[i];
            int exp = min((long long)(idx - pref[idx]) * (suff[idx] - idx), (long long)k);
            ans = (ans * fast_pow(x, exp) % mod);
            k -= exp;
        }
        return ans;
    }
};
