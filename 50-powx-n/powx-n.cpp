class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
        {
            return 1.0;
        }
        long pow = n;
        if(pow<0)
        {
            pow= -pow;
            x= 1.0/x;
        }
        if(pow%2==0)
        {
            return myPow(x*x,pow/2);
        }
        else
        {
            return x* myPow(x,pow-1);
        }
    }
};