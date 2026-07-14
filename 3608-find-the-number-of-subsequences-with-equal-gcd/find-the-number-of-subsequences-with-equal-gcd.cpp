class Solution {
    int memo[201][201][201];
    const int MOD = 1e9 + 7;

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int solve(int idx, int g1, int g2, const vector<int>& nums) {
        if (idx == nums.size()) {
            // Both subsequences must be non-empty and have equal GCDs
            return (g1 > 0 && g1 == g2) ? 1 : 0;
        }

        if (memo[idx][g1][g2] != -1) {
            return memo[idx][g1][g2];
        }

        // Choice 1: Skip the current element
        long long ans = solve(idx + 1, g1, g2, nums);

        // Choice 2: Put the current element in the 1st subsequence
        int next_g1 = (g1 == 0) ? nums[idx] : gcd(g1, nums[idx]);
        ans = (ans + solve(idx + 1, next_g1, g2, nums)) % MOD;

        // Choice 3: Put the current element in the 2nd subsequence
        int next_g2 = (g2 == 0) ? nums[idx] : gcd(g2, nums[idx]);
        ans = (ans + solve(idx + 1, g1, next_g2, nums)) % MOD;

        return memo[idx][g1][g2] = ans;
    }

public:
    int subsequencePairCount(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        return solve(0, 0, 0, nums);
    }
};