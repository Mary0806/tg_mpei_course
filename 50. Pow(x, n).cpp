//https://leetcode.com/problems/powx-n/
class Solution {
public:
    double myPow(double x, long int n) {
        if (n < 0) {
           return  1/myPow (x, -n);
        } else if (n==0) 
            return 1;
        double a=1;
         while (n>0) {
            if (n%2==1) {
                 a*=x;
                n--;
            } 
            else{ 
                x*=x;
                n/=2;
            }
        }
    return a;
    }
    
};
