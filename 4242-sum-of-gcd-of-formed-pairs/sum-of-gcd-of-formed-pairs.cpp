class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixGCD(n);

        int mx=INT_MIN;
        for(int i=0; i<n; i++)
        {
            mx = max(nums[i],mx);
            prefixGCD[i] = std::gcd(nums[i],mx);
        }

        sort(prefixGCD.begin(),prefixGCD.end());

        long long totalSum =0;
        int l=0;
        int r = n-1;
        while(l<r)
        {
            totalSum = totalSum + std::gcd(prefixGCD[l],prefixGCD[r]);
            l++;
            r--;
        }
        return totalSum;
    }
};