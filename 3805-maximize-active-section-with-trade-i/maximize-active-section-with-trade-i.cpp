#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        // Step 1: मूल स्ट्रिंग में कुल कितने '1' हैं
        int total_ones = 0;
        for (char c : s) {
            if (c == '1') total_ones++;
        }

        // Step 2: Augmented string "1" + s + "1"
        string t = "1" + s + "1";
        
        vector<int> zero_lengths;
        vector<int> one_lengths;
        
        int n = t.length();
        int i = 0;

        // Segments की लंबाई निकालें
        while (i < n) {
            if (t[i] == '1') {
                int count = 0;
                while (i < n && t[i] == '1') {
                    count++;
                    i++;
                }
                one_lengths.push_back(count);
            } else {
                int count = 0;
                while (i < n && t[i] == '0') {
                    count++;
                    i++;
                }
                zero_lengths.push_back(count);
            }
        }

        // Step 3: Maximum gain निकालना
        int max_gain = 0;

        // बीच वाले हर 1s-block के लिए
        for (size_t i = 1; i + 1 < one_lengths.size(); i++) {
            // Gain = (बाएं तरफ के 0s) + (दाएं तरफ के 0s)
            int gain = zero_lengths[i - 1] + zero_lengths[i];
            max_gain = max(max_gain, gain);
        }

        return total_ones + max_gain;
    }
};