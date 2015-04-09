/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/

class Solution {
public:
    typedef vector<int>::iterator vit;
    
    void combinationSumAux(vit begin,vit end,vector<int> &one,vector<vector<int> > &res,int target)
    {
        if(target==0){
            res.push_back(one);
            return ;
        }
        else if(target < 0){
            return ;
        }
        
        for(vit it=begin;it<end;++it){
            one.push_back(*it);
            combinationSumAux(it,end,one,res,target-*it);
            one.pop_back();
        }
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > res;
        if(candidates.empty())
            return res;
        
        vector<int> one;
        vit begin = candidates.begin();
        vit end = candidates.end();
        //排序，去重
        sort(begin,end);
        end = unique(begin,end);
        
        combinationSumAux(begin,end,one,res,target);
        
        return res;
    }
};