#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
private:
    // Helper function to calculate the number of unique permutations 
    // for the given character counts, capped at (k + 1) to avoid overflow.
    long long countPermutations(const std::vector<int>& counts, int k) {
        long long res = 1;
        long long M = 0; // Cumulative character count
        
        for (int count : counts) {
            if (count == 0) continue;
            for (int j = 1; j <= count; ++j) {
                M++;
                res = (res * M) / j;
                if (res > k) {
                    return k + 1; // Cap early to prevent overflow
                }
            }
        }
        return res;
    }

public:
    std::string smallestPalindrome(std::string s, int k) {
        int n = s.length();
        std::vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Prepare half frequencies and find middle character if length is odd
        std::vector<int> half_freq(26, 0);
        char mid_char = '\0';
        for (int i = 0; i < 26; ++i) {
            half_freq[i] = freq[i] / 2;
            if (freq[i] % 2 != 0) {
                mid_char = 'a' + i;
            }
        }

        // Check if total possible palindromic permutations are less than k
        long long total = countPermutations(half_freq, k);
        if (total < k) {
            return "";
        }

        int half_len = n / 2;
        std::string first_half = "";

        // Construct the first half character by character
        for (int i = 0; i < half_len; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (half_freq[c] == 0) continue;

                // Try placing character 'a' + c
                half_freq[c]--;
                long long combinations = countPermutations(half_freq, k);

                if (combinations >= k) {
                    // This character is valid at current position
                    first_half += (char)('a' + c);
                    break;
                } else {
                    // Skip these combinations and restore count
                    k -= combinations;
                    half_freq[c]++;
                }
            }
        }

        // Reconstruct full palindrome
        std::string second_half = first_half;
        std::reverse(second_half.begin(), second_half.end());

        if (n % 2 != 0) {
            return first_half + mid_char + second_half;
        } else {
            return first_half + second_half;
        }
    }
};