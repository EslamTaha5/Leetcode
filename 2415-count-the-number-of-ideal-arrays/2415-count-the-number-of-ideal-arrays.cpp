const int mod = 1e9 + 7, N = 1e4 + 5;

int lpf[N];
int dp[N + 20][21];
vector<int> factors[N];
class Solution {
public:
    Solution(){
        for(int i = 2; i < N; i++){
            if(lpf[i]) continue;
            for(int j = i; j < N; j+= i){
                lpf[j] = i;
                int x = j, cnt = 0;
                while(x % i == 0){
                    x /= i;
                    cnt++;
                }
                factors[j].push_back(cnt);
            }
        }
        dp[0][0] = 1;
        for(int i = 1; i < N + 20; i++){
            dp[i][0] = 1;
            for(int j = 1; j <= min(i, 20); j++){
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
            }
        }

    }
    int idealArrays(int n, int maxValue) {
        long long ans = 0;
        for(int i = 1; i <= maxValue; i++){
            long long num = 1;
            for(auto& it: factors[i]){
                (num *= dp[n + it - 1][it]) %= mod;
            }
            (ans += num) %= mod;
        }
        return ans;
    }
};