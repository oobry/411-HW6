#include "path_reconstruct.h"
#include <algorithm> // Needed for std::reverse

std::vector<std::pair<int, int>> reconstruct_path(const std::vector<std::vector<int>>& dp) {
    int i = dp.size() - 1;
    int j = dp[0].size() - 1;
    std::vector<std::pair<int, int>> path;

    while (i > 0 || j > 0) {
        path.push_back({i, j});
        if (i == 0) 
            j--;
        else if (j == 0) 
            i--;
        else {
            if (dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    path.push_back({0, 0});
    std::reverse(path.begin(), path.end());
    return path;
}
