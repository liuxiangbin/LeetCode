/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
    */

    class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0;
        int len = nums.size();
        if(len < 3)
            return res;
            
        sort(nums.begin(),nums.end());
        
        int dis = INT_MAX;
        for(int i=0;i<len-2;++i){
            int a = nums[i];
            int start = i+1, end = len-1;
            while(start < end){
                int sum = a + nums[start] + nums[end] - target;
                if(sum==0){
                    return target;
                }
                else if(sum<0){
                    if(-sum < dis){
                        dis = -sum;
                        res = sum + target;
                    }
                    ++start;
                }
                else{
                    if(sum < dis){
                        dis = sum;
                        res = sum + target;
                    }
                    --end;
                }
            }
        }
        
        return res;
    }
};