class Solution {
public:
    int characterReplacement(string s, int k) {
        int n =s.size();
        int l=0;
        int r=0;
        int maxf=0;
        int maxl=0;
        int h[26]={0};
        for(r=0; r<n; r++)
        {
           h[s[r]-'A']++;
           maxf = max(maxf,h[s[r]-'A']);

           while(r-l+1-maxf>k)
           {
            h[s[l]-'A']--;
            l++;
           }
           maxl = max(maxl,r-l+1);
        }
        return maxl;
    }
};