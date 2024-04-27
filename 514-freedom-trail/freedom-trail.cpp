class Solution {
public:
    int findRotateSteps(string ring, string key) {
          int n = ring.size();
    int m = key.size();

    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

    for (int i = 0; i < n; ++i) {
        if (ring[i] == key[0]) {
            dp[i][0] = min(i, n - i) + 1; 
        }
    }

    for (int j = 1; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (ring[i] != key[j]) continue;
            for (int k = 0; k < n; ++k) {
                if (dp[k][j - 1] != INT_MAX) {
                    int steps = min(abs(i - k), n - abs(i - k)) + 1;
                    dp[i][j] = min(dp[i][j], dp[k][j - 1] + steps);
                }
            }
        }
    }

    int minSteps = INT_MAX;
    for (int i = 0; i < n; ++i) {
        minSteps = min(minSteps, dp[i][m - 1]);
    }

    return minSteps;
    }
};