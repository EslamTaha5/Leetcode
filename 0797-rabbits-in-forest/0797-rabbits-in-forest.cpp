class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        int ans = 0, cnt = 0;
        sort(answers.begin(), answers.end());
        for(int i = 0; i < n; i++){
            if(!answers[i]) ans++;
            else if (i == 0){
                ans += answers[i] + 1;
                cnt = answers[i];
            }else if(answers[i] != answers[i - 1] || cnt == 0){
                ans += answers[i] + 1;
                cnt = answers[i];
            }else{
                cnt--;
            }
        }
        return ans;

    }
};