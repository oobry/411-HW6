#include "max_coins.h"

std::vector<std::vector<int>> compute_max_coins(const std::vector<std::vector<int>>& grid, int &max_coins) {
    int N = grid.size();
    int M = grid[0].size();

    std::vector<std::vector<int>> dp(N, std::vector<int>(M, 0));
    dp[0][0] = grid[0][0];

    for (int j = 1; j < M; j++)
        dp[0][j] = dp[0][j - 1] + grid[0][j];

    for (int i = 1; i < N; i++)
        dp[i][0] = dp[i - 1][0] + grid[i][0];

    for (int i = 1; i < N; i++)
        for (int j = 1; j < M; j++)
            dp[i][j] = grid[i][j] + std::max(dp[i - 1][j], dp[i][j - 1]);

    max_coins = dp[N-1][M-1];
    return dp;
}
