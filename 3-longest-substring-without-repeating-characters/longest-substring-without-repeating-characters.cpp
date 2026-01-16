class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*int n = s.length();
        int maxLength =0;
        vector<int>charIndex(128,-1);
        int left=0;
        int right =0;
        for(right =0; right<n; right++)
        {
            if(charIndex[s[right]]>=left)
            {
                left = charIndex[s[right]]+1;
            }
            charIndex[s[right]]=right;
            maxLength = max(maxLength,right-left+1);
        }
        return maxLength;*/
        unordered_set<char>str;
        int left=0;
        int maxLen=0;
        int n=s.length();
        for(int right=0; right<n; right++)
        {
          while(str.count(s[right]))
          {
            str.erase(s[left]);
            left++;
          }
          str.insert(s[right]);
          maxLen = max(maxLen,right-left+1);
        }
        return maxLen;
    }
};