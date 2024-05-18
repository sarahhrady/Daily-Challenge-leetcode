class Solution {
public:
    bool checkWord(string s, string p)
    {
        int m=0;
        for(int i=0; i<s.size(); i++)
        {
            if(m<p.size()&&s[i]==p[m])m++;
            else if(isupper(s[i]))return false;
        }
        return m==p.size();
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>res;
        for(auto it: queries)
        {
            res.push_back(checkWord(it,pattern));
        }
        return res;
    }
};