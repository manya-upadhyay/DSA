class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
       int res=0;
       const int MOD = 1e9+7;
       int n=nums.size();
       std::sort(nums.begin(),nums.end());
       std:: vector<int>powers(n,1);
       for(int i=1; i<n; i++)
       {
        powers[i] = (powers[i-1]*2)%MOD;
       }
       int left = 0;
       int right =n-1;
       while(left<=right)
       {
        if(nums[left]+nums[right]<=target)
        {
            res=(res+powers[right-left])%MOD;
            left++;
        }
        else
        {
            right--;
        }
       }
       return res;
    }
};