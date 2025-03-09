#include <iostream>
#include "max_coins.h"
#include "path_reconstruct.h"

int main() {
    std::vector<std::vector<int>> grid = {
        {2, 3, 1, 4},
        {1, 5, 2, 1},
        {4, 2, 1, 3}
    };

    int max_coins;
    std::vector<std::vector<int>> dp = compute_max_coins(grid, max_coins);
    std::vector<std::pair<int, int>> path = reconstruct_path(dp);

    std::cout << "Maximum Coins Collected: " << max_coins << std::endl;
    std::cout << "Optimal Path: ";
    for (auto p : path)
        std::cout << "(" << p.first << "," << p.second << ") ";
    std::cout << std::endl;

    return 0;
}
