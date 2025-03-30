class Solution {
public:
    vector<int> partitionLabels(string s) {
        int freq[26]{};
        for(auto& it: s) freq[it - 'a']++;
        vector<int> ans;
        set<int> st;
        for(int i = 0, cnt = 0; i < s.size(); i++){
            cnt++;
            st.insert(s[i] - 'a');

            freq[s[i] - 'a']--;
            bool f= 1;
            for(auto& it: st){
                if(freq[it]) f = 0;
            }
            if(f){
                ans.push_back(cnt);
                cnt = 0;
                st.clear();
            }
        }
        return ans;
    }
};