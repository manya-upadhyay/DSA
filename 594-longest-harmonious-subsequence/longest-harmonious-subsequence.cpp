class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> frequencyMap;
        int maxLength = 0;
        for (int num : nums) {
            frequencyMap[num]++;
        }
        
        for (auto& pair : frequencyMap) {
            int currentNum = pair.first;
            int currentCount = pair.second;

            if (frequencyMap.count(currentNum + 1)) {
    
                int currentSubsequenceLength = currentCount + frequencyMap[currentNum + 1];
                maxLength = max(maxLength, currentSubsequenceLength);
            }
        }
        
        return maxLength;
    }
};