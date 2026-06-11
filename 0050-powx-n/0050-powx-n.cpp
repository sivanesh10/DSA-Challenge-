class Solution {
public:
    double myPow(double x, long long n) {
     //brute --> O(N)
        // int m;
        // if(n < 0) {
        //     m = n;
        //     n = n * (-1);
        // }
        // double ans = 1.00000;
        // for(long long  i=1;i<=n;i++) {
        //     ans *= x;
        // }
        // if(m < 0) return 1/ans;
        // return (double) ans;

        //Optimal

        double ans = 1;
        bool m = false;
        if(n < 0) {
            m = true;
            n = n * (-1);
        }
        while(n > 0) {
            if(n%2 == 0) {
                x = x * x;
                n = n / 2;
            }
            else {
                ans *= x;
                n--;
            }
        }
        return ((m) ? (double) 1.0 / (double) ans : ans);
    }
};