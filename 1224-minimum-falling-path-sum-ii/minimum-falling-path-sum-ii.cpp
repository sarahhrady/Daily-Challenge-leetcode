class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            dp[0][i] = grid[0][i];
        }
        for (int i = 1; i < n; i++) {
            for (int m = 0; m < n; m++) {
                dp[i][m] += grid[i][m];
                int minel = INT_MAX;
                for(int j=0; j<n; j++)
                {
                    if(j==m)continue;
                    minel = min(dp[i - 1][j], minel);
                }
                dp[i][m] += minel;
            }
        }
        int sum = INT_MAX;
        for (int i = 0; i < n; i++) {
            sum = min(sum, dp[n - 1][i]);
        }

        return sum;
    }
};