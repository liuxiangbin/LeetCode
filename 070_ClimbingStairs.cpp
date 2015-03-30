/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution {
public:
    int climbStairs(int n) {
        if(n==0||n==1)
            return 1;
        
        int f0 = 1, f1 = 1;
        int i = 2;
        int tmp;
        while(i<=n){
            tmp = f1;
            f1 += f0;
            f0 = tmp;
            ++i;
        }
        
        return f1;
    }
};