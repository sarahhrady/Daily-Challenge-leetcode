class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> result (s.size(),1);
        vector<int>ls(26,-1);
        for(int i=0; i<s.size(); i++)
        {
            int curr = s[i]-'a';
            for(int j = 0 ; j<26 ; j++)
            {
                if(ls[j]!=-1&&abs(curr-j)<=k)
                {
                    result[i] = max(result[i],result[ls[j]]+1);
                }
            }
            ls[curr]=i;
        }
        //sort(result.begin(),result.end());
        return *max_element(result.begin(), result.end());
    }
};