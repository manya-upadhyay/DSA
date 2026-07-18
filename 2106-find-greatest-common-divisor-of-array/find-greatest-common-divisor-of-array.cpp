class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int miniNum = INT_MAX;
        int maxNum = INT_MIN;
        for(int i=0; i<n; i++)
        {
            miniNum = min(miniNum,nums[i]);
            maxNum = max(maxNum, nums[i]);
        }

        int ans = std::gcd(miniNum,maxNum);
        return ans;
    }
};