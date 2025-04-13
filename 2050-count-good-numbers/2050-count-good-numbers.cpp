class Solution {
public:
#define ll long long
    const ll mod = 1e9 + 7;
    ll calc_power(ll x, ll n){
        ll res = 1;
        x %= mod;
        while(n){
            if(n & 1){
                res *= x;
                res %= mod;
            }
            n >>= 1;
            x *= x;
            x %= mod;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        if(n == 1) return 5;
        ll odd_idx = n / 2;
        ll even_idx = (n + 1) / 2;
        ll odd_ways = calc_power(4, odd_idx);
        ll even_ways = calc_power(5, even_idx) % mod;
        odd_ways *= even_ways;
        odd_ways %= mod;
        return odd_ways; 
    }
};