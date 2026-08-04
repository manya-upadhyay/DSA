class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> present(nums.begin(), nums.end());
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        
        vector<int> missing;
        for (int i = minVal + 1; i < maxVal; ++i) {
            if (!present.count(i)) {
                missing.push_back(i);
            }
        }
        return missing;
    }
};