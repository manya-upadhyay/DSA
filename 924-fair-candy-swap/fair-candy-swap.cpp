class Solution {
public:
    std::vector<int> fairCandySwap(std::vector<int>& aliceSizes, std::vector<int>& bobSizes) {
        // Calculate total candies for both Alice and Bob
        int sumA = std::accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumB = std::accumulate(bobSizes.begin(), bobSizes.end(), 0);
        
        // Calculate the target difference delta
        int delta = (sumB - sumA) / 2;
        
        // Store Bob's candy sizes in a hash set for O(1) lookups
        std::unordered_set<int> bobSet(bobSizes.begin(), bobSizes.end());
        
        // Find the valid pair
        for (int x : aliceSizes) {
            int targetY = x + delta;
            if (bobSet.count(targetY)) {
                return {x, targetY};
            }
        }
        
        return {}; // Guaranteed to have an answer per constraints
    }
};