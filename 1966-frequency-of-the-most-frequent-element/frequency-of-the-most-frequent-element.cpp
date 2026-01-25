class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0;
        int r=0;
        int ans=0;
        long sum=0;
        for(r=0; r<nums.size(); r++)
        {
            sum = sum+nums[r];
            long target = nums[r];
            while((r-l+1)*target -sum>k)
            {
                sum= sum-nums[l];
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};