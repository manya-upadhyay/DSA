class Solution {
public:
    int trap(vector<int>& height) {
        int lmax,rmax, total =0;
        int n= height.size();
        int l=0;
        int r = n-1;
        while(l<=r)
        {
            if(height[l]<=height[r])
            {
                if(lmax>height[l])
                {
                    total = total +lmax-height[l];
                }
                else
                {
                    lmax= height[l];
                }
                l++;
            }
            else
            {
                if(rmax>height[r])
                {
                    total = total + rmax-height[r];
                }
                else
                {
                    rmax= height[r];
                }
                r--;
            }
        }
        return total;
    }
};