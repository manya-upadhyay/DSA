class Solution {
public:
    int binaryGap(int n) {
        int maxGap = 0;
        int lastPosition = -1;
        int currentPosition = 0;

        while (n > 0) {
            if ((n & 1) == 1) {
                if (lastPosition != -1) {
                    // Calculate distance between current and last seen '1'
                    maxGap = max(maxGap, currentPosition - lastPosition);
                }
                // Update the last seen position of '1'
                lastPosition = currentPosition;
            }
            
            // Shift right to check the next bit
            n >>= 1;
            currentPosition++;
        }

        return maxGap;
    }
};