class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
    int atMost(vector<int>&nums, int k)
    {
        int l=0;
        int r=0;
        int cnt=0;
        unordered_map<int,int>freq;
        for(r=0; r<nums.size(); r++)
        {
            freq[nums[r]]++;
            while(freq.size()>k)
            {
                freq[nums[l]]--;
                if(freq[nums[l]]==0)
                {
                    freq.erase(nums[l]);
                }
                l++;
            }
            cnt = cnt+(r-l+1);
        }
        return cnt;
    }
};