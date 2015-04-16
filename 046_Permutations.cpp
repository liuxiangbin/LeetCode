/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        if(num.empty())
            return res;
            
        sort(num.begin(),num.end());
        
        do{
            res.push_back(num);
        }while(next_permutation(num.begin(),num.end()));
        
        return res;
    }
};