class Solution {
public:
    int minAddToMakeValid(string s) {
      int unmatched_operand=0;
      int excess_operand=0;
      for(char c:s)
      {
        if(c=='(')
        {
            unmatched_operand++;
        }
        else if(c==')')
        {
            if(unmatched_operand>0)
            {
                unmatched_operand--;
            }
            else
            {
                excess_operand++;
            }
        }
      }  
      return unmatched_operand + excess_operand;
    }
};