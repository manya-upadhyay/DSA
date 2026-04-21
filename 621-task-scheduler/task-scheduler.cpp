class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Step 1: Count frequencies of each task
        vector<int> freq(26, 0);
        for (char c : tasks) {
            freq[c - 'A']++;
        }
        
        // Step 2: Sort to find the max frequency
        sort(freq.begin(), freq.end(), greater<int>());
        
        int f_max = freq[0];
        int count_max = 0;
        
        // Step 3: Count how many tasks have the max frequency
        for (int f : freq) {
            if (f == f_max) count_max++;
            else break;
        }
        
        // Step 4: Apply the formula
        int ans = (f_max - 1) * (n + 1) + count_max;
        
        // Step 5: Return the max of the formula and the actual task count
        return max(ans, (int)tasks.size());
    }
};