#define ll long long 
class Solution {
public:
    long long dp[20][20][2];
    int n, m,mn;
    bool f;
    
    ll solve(int i, int j, int st, string &s, string &t) {
        if (j == m) {
            if (!f)return st;
            return 1;
        }
        ll &ret = dp[i][j][st];
        if(~ret)return ret;
        int rem = n - i;
        ret = 0;

        if (rem == m - j) {
            char a = s[i], b = t[j];
            if (a < b && st == 0);
            else {
                ret += solve(i + 1, j + 1, st|(a>b), s, t);
            }
        } else {
            int mx = 9;
            if (!st)mx = s[i] - '0';
            mx = min(mx,mn);
            for (int k = 0; k <= mx; k++) {
                ret += solve(i + 1, j, st | (k < s[i] - '0'), s, t);
            }
        }
        return ret;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string a, b;
        mn = limit;
        a = to_string(start);
        b = to_string(finish);
        while (a.size() < s.size())a = '0' + a;
        memset(dp, -1, sizeof dp);
        m = s.size();
        n = a.size();
        long long x = solve(0, 0, 0, a, s);
        f = 1;
        n = b.size();
        memset(dp, -1, sizeof dp);
        ll y = solve(0, 0, 0, b, s);
        return y - x;
    }
};
