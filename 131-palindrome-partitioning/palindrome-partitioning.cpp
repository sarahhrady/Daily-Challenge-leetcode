class Solution {
public:
    bool isPlandirome(int start, int end, string& s)
    {
        while(start<end)
        {
            if(s[start]!=s[end])return false;
            start++;
            end--;
        }
        return true;
    }
    
    vector<vector<string>>vv;
    vector<string> path;
    void backtrack(int start, string& s)
    {
        if(start==s.size())vv.push_back(path);

        for(int e=start; e<s.size(); e++)
        {
            if(isPlandirome(start,e,s)){
                path.push_back(s.substr(start,e-start+1));
                 backtrack(e+1,s);
                 path.pop_back();
            }
           
        }
    }
    vector<vector<string>> partition(string s) {
        backtrack(0,s);
        return vv;
    }
};