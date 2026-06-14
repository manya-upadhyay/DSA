class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        for(char c: address)
        {
            if(c== '.')
            {
                res = res + "[.]";
            }
            else
            {
                res = res + c;
            }
        }
        return res;
    }
};