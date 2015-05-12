/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

class Solution {
public:
    string d2c[10] = {"0","0","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void letterCombinationsAux(int index,int len,string &s,string &digits,vector<string> &res)
    {
        if(index==len){
            res.push_back(s);
            return;
        }
        
        string tmp = d2c[digits[index]-'0'];
        for(int i=0;i<tmp.size();++i){
            s.push_back(tmp[i]);
            letterCombinationsAux(index+1,len,s,digits,res);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int len = digits.size();
        if(len==0)
            return res;
            
        string s;
        letterCombinationsAux(0,len,s,digits,res);
        
        return res;
    }
};