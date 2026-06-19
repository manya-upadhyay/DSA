class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        std::unordered_map<int,int>cnt;
        for(int num: nums)
        {
            cnt[num]++;
        }

        std::sort(nums.begin(), nums.end(), [&cnt](int a, int b)
        {
            if(cnt[a]!=cnt[b])
            {
                return cnt[a]<cnt[b];
            }
            return a>b;
        });
    return nums;
    }
};