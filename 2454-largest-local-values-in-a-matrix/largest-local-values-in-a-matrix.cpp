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
        vector<vector<int>>v(n-2, vector<int>(n-2));
        for(int i=0; i<n-2; i++)
        {
            for(int j=0; j<n-2; j++)
            {
                v[i][j]=maxN(n-2,i,j,grid);
            }
        }
        return v;
    }
};