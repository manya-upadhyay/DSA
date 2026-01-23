class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l =0; 
        int r=0;
        int maxlength = 0;
         int zeroes =0;
         for(r=0; r<nums.size(); r++)
         {
            if(nums[r]==0)
            {
                zeroes++;
            }
         while(zeroes>k)
         {
            if(nums[l]==0)
            {
                zeroes--;
            }
            l++;
         }
         maxlength= max(maxlength,r-l+1);
         }
         return maxlength;
    }
};