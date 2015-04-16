/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

//STL 的序列产生算法对具有相同元素的序列也适用
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
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