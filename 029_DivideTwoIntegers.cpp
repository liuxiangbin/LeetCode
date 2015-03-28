/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

class Solution {
public:
    #define MAX_INT 0x7fffffff
    #define MIN_INT 0x80000000

    int divide(int dividend, int divisor) {
        if(divisor == 0 ||(dividend==MIN_INT&&divisor==-1))
            return MAX_INT;
        
        int flagOfDividend = 0;
        long long dividendTmp = dividend;
        if(dividendTmp < 0 ){
            flagOfDividend = 1;
            dividendTmp = -dividendTmp;
        }
        int flagOfDivisor = 0;
        long long divisorTmp = divisor;
        if(divisorTmp < 0 ){
            flagOfDivisor = 1;
            divisorTmp = -divisorTmp;
        }
        
        int cnt = 0;
        while(dividendTmp >=divisorTmp){
            int i = 0;
            while(dividendTmp>=(divisorTmp<<i)){
                cnt += 1<<i;
                dividendTmp -= divisorTmp<<i;
                ++i;
            }
        }
        
        if(flagOfDividend == flagOfDivisor)
            return cnt;
        else
            return -cnt;
    }
};