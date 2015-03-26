/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

class Solution {
public:
    void generate(int leftNum,int rightNum,string str,vector<string>& res)
    {
        if(leftNum==0&&rightNum==0)
            res.push_back(str);
        
        if(leftNum > 0){
            generate(leftNum-1,rightNum,str+'(',res);
        }
        
        if(rightNum>0&&leftNum<rightNum){
            generate(leftNum,rightNum-1,str+')',res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string>  res;
        
        if(n==0)
            return res;
        
        string str;
        generate(n,n,str,res);
        
        return res;
    }
};