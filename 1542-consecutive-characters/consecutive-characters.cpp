class Solution {
public:
    int maxPower(string s) {
        if(s.empty())
        {
            return 0;
        }

        int maxPow =1;
        int currPow=1;
        for(int i=1; i<s.length(); i++)
        {
            if(s[i]==s[i-1])
            {
                currPow++;
            }
            else
            {
                currPow=1;
            }
            maxPow= max(maxPow,currPow);
        }
    return maxPow;
    }
};