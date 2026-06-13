class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> min_freq(26, 101);
        for (const string& word : words) {
            vector<int> char_freq(26, 0);
            for (char ch : word) {
                char_freq[ch - 'a']++;
            }

            for (int i = 0; i < 26; ++i) {
                min_freq[i] = min(min_freq[i], char_freq[i]);
            }
        }
        vector<string> result;
        for (int i = 0; i < 26; ++i) {
            while (min_freq[i] > 0 && min_freq[i] != 101) {
                result.push_back(string(1, 'a' + i));
                min_freq[i]--;
            }
        }
        
        return result;
    }
};