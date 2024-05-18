class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        for(int i=0; i<s.size(); i++)
        {
            string ss;
            if(s[i]==' ')continue;
            while(s[i]!=' '&&i<s.size())
            {
                ss.push_back(s[i]);
                i++;
            }
            v.push_back(ss);
        }
        string res;
        for(int i=v.size()-1; i>=0; i--)
        {
            res+=(i!=v.size()-1?(' '+v[i]):v[i]);
        }
        return res;
    }
};