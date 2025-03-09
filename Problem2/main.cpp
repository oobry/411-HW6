#include <iostream>
#include <vector>  // <-- Add this line for std::vector
#include "coin_change.h"

int main() {
    std::vector<int> coins = {1, 5, 10};
    int amount = 12;

    int result = min_coins(amount, coins);

    if (result == -1)
        std::cout << "No solution possible." << std::endl;
    else
        std::cout << "Minimum coins needed: " << result << std::endl;

    return 0;
}
