class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // Step 1: Sort the array in ascending order
        sort(arr.begin(), arr.end());
        
        int minDiff = INT_MAX;
        vector<vector<int>> result;
        
        // Step 2: Find the minimum absolute difference
        for (int i = 0; i < arr.size() - 1; ++i) {
            int diff = arr[i + 1] - arr[i];
            if (diff < minDiff) {
                minDiff = diff;
            }
        }
        
        // Step 3: Collect all pairs with the minimum difference
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i + 1] - arr[i] == minDiff) {
                result.push_back({arr[i], arr[i + 1]});
            }
        }
        
        return result;
    }
};