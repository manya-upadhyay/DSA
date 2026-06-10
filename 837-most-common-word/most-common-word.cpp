class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // Store banned words in a hash set for O(1) lookups
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string, int> wordCount;
        
        string currentWord = "";
        string mostFrequent = "";
        int maxCount = 0;
        
        // Append a space at the end to flush out the last word easily
        paragraph += " "; 
        
        for (char c : paragraph) {
            if (isalpha(c)) {
                // Build the word in lowercase
                currentWord += tolower(c);
            } else {
                // If we hit a punctuation mark or space, process the accumulated word
                if (!currentWord.empty()) {
                    if (bannedSet.find(currentWord) == bannedSet.end()) {
                        wordCount[currentWord]++;
                        if (wordCount[currentWord] > maxCount) {
                            maxCount = wordCount[currentWord];
                            mostFrequent = currentWord;
                        }
                    }
                    currentWord = ""; // Reset for the next word
                }
            }
        }
        
        return mostFrequent;
    }
};