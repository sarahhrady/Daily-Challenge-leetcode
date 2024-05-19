class Solution {
public:
    string lastNonEmptyString(string s) {
        map<char, int> m;
        for (char c : s) m[c]++;
        
        string res = "";
        int maxx = 0;
        for (auto it : m) {
            maxx = max(maxx, it.second);
        }

        set<char> se;
        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] == maxx) se.insert(s[i]);
        }

        /*int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] == maxx) {
                cnt++;
                m[s[i]] = 0;
            }
        }*/

        for (int i = s.size() - 1; i >= 0; i--) {
            //if (cnt == 0) break;
            if (se.count(s[i]) > 0) {
                res.push_back(s[i]);
                se.erase(s[i]);
               // cnt--;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};