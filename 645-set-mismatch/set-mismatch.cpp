class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
      int n = nums.size();
      std::vector<int>cnt(n+1,0);
      int duplicate =-1;
      int missing = -1;
      for(int num: nums)
      {
        cnt[num]++;
      }  

      for(int i=0; i<=n; i++)
      {
        if(cnt[i]==2)
        {
            duplicate =i;
        }
        else if(cnt[i]==0)
        {
            missing =i;
        }
      }
      return {duplicate,missing};
    }
};