class Solution {
public:
    int maximum69Number (int num) {
        std::string numStr = std::to_string(num);
        for (char &ch : numStr) {
            if (ch == '6') {
                ch = '9'; 
                break;    
            }
        }
        return std::stoi(numStr);
    }
};