class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> digits;
        long long sum = 0;
        
        // Extract non-zero digits from right to left
        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) {
                digits.push_back(digit);
                sum += digit;
            }
            n /= 10;
        }
        
        // Reconstruct x in the original order
        long long x = 0;
        for (int i = digits.size() - 1; i >= 0; --i) {
            x = x * 10 + digits[i];
        }
        
        return x * sum;
    }
};