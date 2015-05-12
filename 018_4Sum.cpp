/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        int len = nums.size();
        if(len < 4)
            return res;
            
        sort(nums.begin(),nums.end());
        
        vector<int> one(4,0);
        int a,b;
        int start,end;
        for(int i=0;i<len-3;++i){
            a = nums[i];
            for(int j=i+1;j<len-2;++j){
                b = nums[j];
                start = j+1;
                end = len-1;
                while(start<end){
                    int sum = a + b + nums[start] + nums[end];
                    if(sum == target){
                        one[0] = a;
                        one[1] = b;
                        one[2] = nums[start];
                        one[3] = nums[end];
                        res.push_back(one);
                        while(start<end&&nums[start+1]==nums[start]) ++start;
                        ++start;
                        while(start<end&&nums[end-1]==nums[end]) --end;
                        --end;
                    }
                    else if(sum < target){
                        ++start;
                    }
                    else{
                        --end;
                    }
                }
                while(nums[j+1]==b) ++j;
            }
            while(nums[i+1]==a) ++i;
    }
    
    return res;
  }
};
