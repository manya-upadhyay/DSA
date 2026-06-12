class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int prev_group_len = 0;
        int curr_group_len = 1; // Start counting the first character
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                // If the character is the same as the previous one, extend the current group
                curr_group_len++;
            } else {
                // Character changed! Add the valid substrings formed by the last two groups
                ans += min(prev_group_len, curr_group_len);
                // Move current group to previous, and reset current group length to 1
                prev_group_len = curr_group_len;
                curr_group_len = 1;
            }
        }
        
        // Don't forget to add the valid substrings formed by the final two groups
        ans += min(prev_group_len, curr_group_len);
        
        return ans;
    }
};