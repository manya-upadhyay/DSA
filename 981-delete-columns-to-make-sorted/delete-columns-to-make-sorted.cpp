class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();
        int deletionCount = 0;

        // Iterate through each column
        for (int c = 0; c < cols; ++c) {
            // Check rows from top to bottom for the current column
            for (int r = 1; r < rows; ++r) {
                if (strs[r][c] < strs[r - 1][c]) {
                    deletionCount++;
                    break; // No need to check the rest of this column
                }
            }
        }

        return deletionCount;
    }
};