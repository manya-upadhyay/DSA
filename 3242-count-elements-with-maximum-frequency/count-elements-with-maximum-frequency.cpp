class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num : nums)
        {
            mp[num]++;
        }
        int max , count ;
        for(auto it: mp)
        {
            
            if(it.second > max)
            {
                max = it.second;
                count = 1;
            }
            else if(max == it.second)
            {
                count++;
            }
        }
        if(max == 1)
        {
            return mp.size();
        }
        return max*count;
    }
};