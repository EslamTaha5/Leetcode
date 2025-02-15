
class Solution {
public:
    vector<int> prefix_function(const string &s) {
        int n = s.size();
        vector<int> pi(n);
        for (int i = 1, j = 0; i < n; i++) {
            while (j && s[i] != s[j]) j = pi[j - 1];
            if (s[i] == s[j]) j++;
            pi[i] = j;
        }
        return pi;
    }

    vector<vector<int> > elpis;
    vector<pair<int, vector<int> > > elmatches;

    bool valid(int mid, int n) {
        for (int i = 0, j = 0; i < n; i++) {
            if (i - j + 1 == mid) {
                int id = j;
                bool f = 1;
                for (int k = 0; k < elmatches.size(); k++) {
                    // find kth part and the end of the previous part at id
                    auto it = lower_bound(elmatches[k].second.begin(), elmatches[k].second.end(),
                                          id);
                    if (it == elmatches[k].second.end() ||
                        *it + elmatches[k].first - 1 > i) {

                        f = 0;
                        break;
                    }
                    id = *it + elmatches[k].first;
                }
                if (f) return true;
                j++;
            }
        }
        return false;
    }

    int shortestMatchingSubstring(string s, string p) {
        string t;
        p += '*';
        for (int i = 0; i < (int) p.size(); i++) {
            if (p[i] == '*') {
                if (t.size()) {
                    elpis.push_back(prefix_function(t + '#' + s));
                    elmatches.push_back({t.size(), vector<int>()});
                    for (int j = 0; j < elpis.back().size(); j++) {
                        if (elpis.back()[j] == t.size()) {
                            elmatches.back().second.push_back(j - (2 * t.size()));
                        }
                    }
                    /*cout << t << " " << elmatches.back().first << endl;
                    for (auto &it: elmatches.back().second) {
                        cout << it << " ";
                    }
                    cout << endl;*/
                }
                t = "";
            } else t += p[i];
        }
        if (elmatches.empty()) return 0;
        p.pop_back();
       
        int l = 0, r = s.size(), mid, ans = -1;
        while (l <= r) {
            mid = (l + r) / 2;
            if (valid(mid, s.size())) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    }
};