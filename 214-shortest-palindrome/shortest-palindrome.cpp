class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int i=0, j=n-1;
        while(j>=0)
        {
            if(s[i]==s[j])
            {
                i++;
            }
            j--;
        }
        if(i==n)
        {
            return s;
        }
        string remain= s.substr(i);
        string rev_remain= remain;
        reverse(rev_remain.begin(),rev_remain.end());
        return rev_remain + shortestPalindrome(s.substr(0,i))+remain;
    }
};