class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        std::unordered_set<int> uniqueCandies(candyType.begin(), candyType.end());
        
        // Alice can eat at most n / 2 candies
        int maxAllowed = candyType.size() / 2;
        
        // The answer is the minimum of unique types available and the max allowed limit
        return std::min(uniqueCandies.size(), static_cast<size_t>(maxAllowed));
        
    }
};