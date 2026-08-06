class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true)
        {
            int pro =1;
            int x=n;

            while(x>0)
            {
                pro = pro*(x%10);
                x/=10;
            }
            if(pro%t==0)
            {
                return n;
            }
            n++;
        }
    }
};