#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = *max_element(nums.begin(), nums.end());
        
        // Step 1: Count frequency of each number
        vector<long long> count(max_val + 1, 0);
        for (int num : nums) {
            count[num]++;
        }
        
        // Step 2 & 3: Compute exact pair counts for each GCD using a sieve-like approach
        vector<long long> gcd_pairs(max_val + 1, 0);
        for (int i = max_val; i >= 1; --i) {
            long long multiples = 0;
            for (int j = i; j <= max_val; j += i) {
                multiples += count[j];
            }
            
            // Total pairs where both elements are multiples of i
            long long total_pairs = (multiples * (multiples - 1)) / 2;
            
            // Subtract pairs that have a larger GCD (multiples of i)
            for (int j = 2 * i; j <= max_val; j += i) {
                total_pairs -= gcd_pairs[j];
            }
            gcd_pairs[i] = total_pairs;
        }
        
        // Step 4: Compute prefix sums of the pair counts
        vector<long long> prefix_sums(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            prefix_sums[i] = prefix_sums[i - 1] + gcd_pairs[i];
        }
        
        // Step 5: Answer each query using binary search
        vector<int> ans;
        ans.reserve(queries.size());
        for (long long q : queries) {
            // Find the first GCD value where the prefix sum is strictly greater than q
            auto it = upper_bound(prefix_sums.begin(), prefix_sums.end(), q);
            ans.push_back(distance(prefix_sums.begin(), it));
        }
        
        return ans;
    }
};