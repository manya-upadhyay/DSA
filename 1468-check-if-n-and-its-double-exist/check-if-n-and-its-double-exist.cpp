class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
     std::unordered_set<int> seen;
        
        for (int x : arr) {
            // Check if the double or half of the current number exists in the set
            if (seen.count(2 * x) || (x % 2 == 0 && seen.count(x / 2))) {
                return true;
            }
            // Add the current number to the set
            seen.insert(x);
        }
        
        return false;   
    }
};