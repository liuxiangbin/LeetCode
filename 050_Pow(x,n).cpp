/*
Implement pow(x, n).
*/

class Solution {
public:
    double pow_aux(double x, long long n) {
        if(n==1)
            return x;
        
        if(n & 0x1){
            double res = pow_aux(x,n/2);
            return x*res*res;
        }
        else{
            double res = pow_aux(x,n/2);
            return res*res;
        }
    }
    
    double pow(double x,int n){
        if(n == 0)
            return 1.0;
        
        bool positive = true;
        long long nn = n;
        if(nn < 0){
            positive = false;
            nn = -nn;
        }
        
        double res = pow_aux(x,nn);
        
        if(positive)
            return res;
        else
            return 1/res;
    }
};