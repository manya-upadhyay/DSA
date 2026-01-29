class Solution {
public: int numSubarraysWithSum(vector<int>& nums, int goal) {
       if(goal==0)
       {
        return slidingWindowTwoPointer(nums,goal);
       }
    return slidingWindowTwoPointer(nums,goal)-slidingWindowTwoPointer(nums,goal-1);
    }
      int slidingWindowTwoPointer(vector<int>& nums, int goal)
    {
        int l=0;
        int r=0;
        int cnt=0;
        int sum=0;
        for(r=0; r<nums.size(); r++)
        {
            sum=sum+nums[r];
            while(sum>goal)
            {
                sum= sum-nums[l];
                l++;
            }
            cnt = cnt + (r-l+1);
        }
        return cnt;
    }
};