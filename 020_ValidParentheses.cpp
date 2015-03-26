/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        if(s.empty())
            return true;
        
        stack<char> ss;
        ss.push(s[0]);
        
        for(int i=1;i<s.size();++i){
            if(ss.empty()){
                ss.push(s[i]);
                continue;
            }
            if(ss.top()=='(' && s[i]==')'){
                ss.pop();
                continue;
            }
            if(ss.top()=='['&&s[i]==']'){
                ss.pop();
                continue;
            }
            if(ss.top()=='{'&&s[i]=='}'){
                ss.pop();
                continue;
            }
            
            ss.push(s[i]);
        }
        
        if(ss.empty())
            return true;
        else
            return false;
    }
};