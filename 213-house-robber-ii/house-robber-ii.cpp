class Solution {
public:
    int rob(vector<int>& nums) {
       int n = nums.size();
       if(n==0)
       {
        return 0;
       } 
       if(n==1)
       {

        return nums[0];
       }

       return max(roblinear(nums,0,n-2), roblinear(nums,1,n-1));
    }

private:
    int roblinear(vector<int>&nums, int start, int end)
    {
        int prev2=0;
        int prev1=0;
        for(int i = start; i<=end; i++)
        {
            int curr = max(prev1,prev2+nums[i]);
            prev2= prev1;
            prev1= curr;
        }
        return prev1;
    }
};