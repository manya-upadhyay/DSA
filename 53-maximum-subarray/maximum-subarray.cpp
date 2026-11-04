class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int res = nums[0];
        for(int n : nums)
        {
            if(sum<0)
            {
                sum=0;
            }
            sum= sum+n;
            res= max(res,sum);
        }
        return res;
    }
};