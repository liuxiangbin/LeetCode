/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len==0)
            return 0;
        
        //for all number is <=0
        int max = nums[0];
        for(int i=1;i<len;++i){
            if(nums[i]>max)
                max = nums[i];
        }
        if(max <=0)
            return max;
      
        int maxsum = 0,sum = 0;
        for(int i=0;i<len;++i){
            sum += nums[i];
            if(sum>=0){
                maxsum = sum>maxsum?sum:maxsum;
            }
            else{
                sum = 0;
            }
        }
        
        return maxsum;
    }
};