/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

//Solution 1: Recursion (TLE)
class Solution {
public:
    typedef vector<int>::iterator vit;
    
    int rob_aux(vit begin,vit end)
    {
        if(begin==end)
            return 0;
        else if(begin+1==end)
            return *begin;
        else if(begin+2==end)
            return max(*begin,*(begin+1));
        
        return max(*begin+rob_aux(begin+2,end),rob_aux(begin+1,end));
    }

    int rob(vector<int> &num) {
        if(num.empty())
            return 0;
        
        return rob_aux(num.begin(),num.end());
    }
};

//Solution 2: DP(3ms),we can see dp's power 
//dp[i] = max(dp[i-2]+num[i],dp[i-1])
class Solution {
public:
    int rob(vector<int> &num) {
        int len = num.size();
        if(len==0)
            return 0;
        else if(len==1)
            return num[0];
        
        int dp[len] = {0};
        dp[0] = num[0];
        dp[1] = max(num[0],num[1]);
        
        for(int i=2;i<len;++i){
            dp[i] = max(dp[i-2]+num[i],dp[i-1]);
        }
        
        return dp[len-1];
    }
};