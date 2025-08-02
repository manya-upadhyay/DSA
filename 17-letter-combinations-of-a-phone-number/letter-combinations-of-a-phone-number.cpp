class Solution {
public:
   
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        string s;
        unordered_map<char, string>mp= {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        if(digits.length()>0) rec(res,s,mp,digits,0);
        return res;
    }

    void rec(vector<string>&res, string &s, unordered_map<char,string>&mp,string &digits, int i) 
    {
        if(digits.length()==s.length())
        {
            res.push_back(s);
        }
        for(char c:mp[digits[i]])
        {
            s.push_back(c);
            rec(res,s,mp,digits,i+1);
            s.pop_back();
        }
    }
};