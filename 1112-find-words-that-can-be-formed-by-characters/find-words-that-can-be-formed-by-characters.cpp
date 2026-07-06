
class Solution {
public:
    int countCharacters(std::vector<std::string>& words, std::string chars) {
        std::vector<int> charCounts(26, 0);
        for (char c : chars) {
            charCounts[c - 'a']++;
        }
        
        int totalLength = 0;
    
        for (const std::string& word : words) {
            std::vector<int> wordCounts(26, 0);
            for (char c : word) {
                wordCounts[c - 'a']++;
            }
            
            bool canForm = true;
        
            for (int i = 0; i < 26; ++i) {
                if (wordCounts[i] > charCounts[i]) {
                    canForm = false;
                    break;
                }
            }
            
          
            if (canForm) {
                totalLength += word.length();
            }
        }
        
        return totalLength;
    }
};