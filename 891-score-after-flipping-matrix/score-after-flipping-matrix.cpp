class Solution {
public:
    int bin(vector<int>& raw) {
        int dec = 0;
        int base = 1;
        for (int i = raw.size() - 1; i >= 0; --i) {
            dec += raw[i] * base;
            base *= 2;
        }
        return dec;
    }
    int matrixScore(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < grid[0].size(); j++) {
                    grid[i][j] = (grid[i][j]) == 0 ? 1 : 0;
                }
            }
        }
        for (int i = 0; i < grid[0].size(); i++) {
            int cntzeros = 0, cntones = 0;
            for (int j = 0; j < grid.size(); j++) {
                if (grid[j][i] == 0) {
                    cntzeros++;
                } else {
                    cntones++;
                }
            }
            if (cntzeros > cntones) {
                 for (int j = 0; j < grid.size(); j++) {
                    grid[j][i] = 1 - grid[j][i];
                }
            }
        }

        int sum = 0;
        for (auto& row : grid) {
            sum += bin(row);
        }
        return sum;
    }
};