class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int>m;
        for(vector<int> i:edges)
        {
            m[i[0]]++;
            m[i[1]]++;
        }
        for(pair<int,int>p:m)
        {
            int n= p.first;
            int d = p.second;

            if(d==edges.size())return n;
        }
        return -1;
    }
};