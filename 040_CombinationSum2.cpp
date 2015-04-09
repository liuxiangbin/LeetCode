/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

class Solution {
public:
    typedef vector<int>::iterator vit;
    
    void combinationSum2Aux(vit begin,vit end,vector<int> &one,vector<vector<int> > &res,int target)
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
            combinationSum2Aux(it+1,end,one,res,target-*it);
            one.pop_back();
        }
    }

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > res;
        if(num.empty())
            return res;
            
        vector<int> one;
        vit begin = num.begin();
        vit end = num.end();
        sort(begin,end);
        combinationSum2Aux(begin,end,one,res,target);
        
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        
        return res;
    }
};