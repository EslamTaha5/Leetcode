class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0, a = -1, b = -1;

        for(int i = 0 ;i < s1.size(); i++){
            if(s1[i] != s2[i]){
                cnt++;
                if(a == -1) a = i;
                else b = i;
            }
        }
        return (cnt == 2  && s1[a] == s2[b] && s2[a] == s1[b]) || cnt == 0;
    }
};