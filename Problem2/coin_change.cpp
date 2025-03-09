#include "coin_change.h"
#include <vector>
#include <limits>  // For infinity constant

int min_coins(int amount, const std::vector<int>& coins) {
    const int INF = std::numeric_limits<int>::max(); // Represents "impossible"
    std::vector<int> dp(amount + 1, INF);
    
    dp[0] = 0; // Base case: 0 coins needed to make amount 0

    for (int i = 1; i <= amount; i++) {
        for (int c : coins) {
            if (i >= c && dp[i - c] != INF) { // Ensure no overflow
                dp[i] = std::min(dp[i], dp[i - c] + 1);
            }
        }
    }

    return (dp[amount] == INF) ? -1 : dp[amount]; // Return -1 if no solution
}
