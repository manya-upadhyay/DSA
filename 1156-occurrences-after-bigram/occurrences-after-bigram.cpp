class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words;
        vector<string> result;
        stringstream ss(text);
        string word;
        
        // Split the text by spaces and store into a vector of words
        while (ss >> word) {
            words.push_back(word);
        }
        
        // Traverse the words to find matches for "first second third"
        // We stop at words.size() - 2 to prevent going out of bounds
        if (words.size() < 3) return result;
        
        for (size_t i = 0; i < words.size() - 2; ++i) {
            if (words[i] == first && words[i + 1] == second) {
                result.push_back(words[i + 2]);
            }
        }
        
        return result;
    }
};