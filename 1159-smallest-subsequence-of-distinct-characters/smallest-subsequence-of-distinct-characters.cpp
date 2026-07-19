class Solution {
public:
    string smallestSubsequence(string s) {

        vector<int> lastIndex(26, 0);
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }
        
        vector<bool> seen(26, false);
        string result = "";
        
        for (int i = 0; i < s.size(); i++) {
            char curr = s[i];
        
            if (seen[curr - 'a']) continue;
           
            while (!result.empty() && result.back() > curr && lastIndex[result.back() - 'a'] > i) {
                seen[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            result.push_back(curr);
            seen[curr - 'a'] = true;
        }
        
        return result;
    }
};