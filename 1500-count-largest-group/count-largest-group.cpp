class Solution {
private:
    // Helper function to calculate the sum of digits of a number
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int countLargestGroup(int n) {
        // Max possible digit sum for n <= 10000 is 36 (from 9999)
        std::vector<int> groupSizes(37, 0);
        int maxSize = 0;

        // Group numbers from 1 to n by their digit sum
        for (int i = 1; i <= n; ++i) {
            int sum = getDigitSum(i);
            groupSizes[sum]++;
            maxSize = std::max(maxSize, groupSizes[sum]);
        }

        // Count how many groups achieved the maximum size
        int largestGroupCount = 0;
        for (int size : groupSizes) {
            if (size == maxSize) {
                largestGroupCount++;
            }
        }

        return largestGroupCount;
    }
};

