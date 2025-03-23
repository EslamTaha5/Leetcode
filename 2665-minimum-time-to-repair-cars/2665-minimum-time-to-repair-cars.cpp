class Solution {
public:
#define ll long long
    long long repairCars(vector<int>& ranks, int cars) {
        auto valid = [&](ll mid)->bool{
            ll cnt = 0;
            for(auto& it: ranks){
                ll x = mid / it;
                cnt += sqrtl(x);
                if(cnt >= cars) return true;
            }
            return cnt >= cars? true: false;

        };
        ll l = 0, r = 1e15, mid, ans;
        while(l <= r){
            mid = l + r >> 1;
            if(valid(mid)){
                r = mid - 1;
                ans = mid;
            }else l = mid + 1;
        }
        return ans;
    }
};