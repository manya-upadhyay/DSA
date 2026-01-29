class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
      return func(nums,k)-func(nums,k-1); 
    }
    int func(vector<int>&nums, int k)
    {
        if(k<0)
        {
            return 0;
        }
        int l=0;
        int r=0;
        int sum=0;
        int cnt=0;
        for(r=0; r<nums.size(); r++)
        {
            sum = sum+(nums[r]%2);

            while(sum>k)
            {
               sum= sum-(nums[l]%2);
               l++;
            }
            cnt = cnt+(r-l+1);
        }
        return cnt;
    }
};