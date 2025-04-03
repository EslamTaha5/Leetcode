class Solution {
public:

    long long maximumTripletValue(vector<int>& v) {
                int n = v.size();

        vector<long long>suff(n+2);
        suff[n-1]=v[n-1];
        for(int i = n-2;i>=0;i--){
            suff[i]=max(suff[i+1],1ll*v[i]);
        }
        long long ans = 0;
        long long pref = v[0];
        for(int i = 1;i<n-1;i++){
            if(v[i]>=pref)pref = v[i];
            else{
                ///cout<<pref<<" "<<v[i]<<" "<<suff[i+1]<<endl;
                ans = max(ans,1ll*suff[i+1]*(pref-v[i]));
            }
        }
        return ans;
    }
};