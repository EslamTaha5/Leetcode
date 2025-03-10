class Solution {
public:
    bool valid(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    long long calc(string s, int k){
        map<char, int> vowels;
        long long cnt = 0, cnt2 = 0, ans = 0, n = s.size();
        for(int i = 0, j = 0; i < n;i++){
            
            if(valid(s[i])){
                vowels[s[i]]++;
            }else cnt2++;
            while(vowels.size() == 5 && cnt2 >= k){
                ans += n - i;
                if (valid(s[j])) {
                    if (--vowels[s[j]] == 0) {
                        vowels.erase(s[j]);
                    }
                }else{
                    cnt2--;
                }
                j++;
            }
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        return max(0ll, calc(word, k) - calc(word, k + 1));
    }
};