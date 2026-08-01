#include <vector>
#include <algorithm>

class Solution {
public:
    bool predictTheWinner(std::vector<int>& nums) {
        int n = nums.size();
        
        // dp[i][j] stores the maximum relative score difference 
        // Player 1 can achieve over Player 2 for subarray nums[i...j]
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        
        // Base case: Subarray of length 1
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }
        
        // Fill DP table for lengths 2 to n
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                
                int pickLeft = nums[i] - dp[i + 1][j];
                int pickRight = nums[j] - dp[i][j - 1];
                
                dp[i][j] = std::max(pickLeft, pickRight);
            }
        }
        
        // Player 1 wins if total relative score difference is non-negative
        return dp[0][n - 1] >= 0;
    }
};