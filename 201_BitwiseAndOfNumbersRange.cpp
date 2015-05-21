/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m==0)
            return 0;
        if(m==n)
            return m;
        
        long long cnt = 2;
        while(cnt <= m)
            cnt *= 2;
            
        if(n>=cnt)
            return 0;
            
        int res = n;
        for(int i=m;i<n;++i){
            res &= i;
        }
        
        return res;
    }
};