class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt=0;
        int l=0;
        int r=0;
        unordered_map<char,int>char_cnt= {{'a',0},{'b',0},{'c',0}};
        for(r=0; r<s.length(); r++)
        {
          char_cnt[s[r]]++;
          while(char_cnt['a']>0 && char_cnt['b']>0 && char_cnt['c']>0)
          {
            cnt = cnt+ s.length()-r;
            char_cnt[s[l]]--;
            l++;
          }
        }
        return cnt;
    }
};