class Solution {
public:
    int maxN (int n, int x, int y, vector<vector<int>>& matrix)
    {
        int res = INT_MIN;
        for(int i=x; i<x+3; i++)
        {
            for(int j=y; j<y+3; j++)
            {
                res = max(res,matrix[i][j]);
            }
        }
        return res;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>v;
        for(int i=0; i<n-2; i++)
        {
            vector<int>row;
            for(int j=0; j<n-2; j++)
            {
                row.push_back(maxN(n-2,i,j,grid));
            }
            v.push_back(row);
        }
        return v;
    }
};