/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

//Solution 1:O(n^2)->Time Limit Exceeded
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty())
            return 0;
            
        int res = 0;    
        int left, right;
        int len = s.size();
        for(int i=0;i<len;++i){
            left = 0;
            right = 0;
            for(int j=i;j<len;++j){
                if(left>=right){
                    if(s[j]=='(')
                        ++left;
                    else
                        ++right;
                }
                else{
                    res = 2*left>res?2*left:res;
                    break;
                }
            }
        }
        
        return res;
    }
};

//Solution 2：DP
class Solution {
public:
    int longestValidParentheses(string s) {
        int len =s.size();
        if(len<=1)
            return 0;
        
        vector<int> dp(len,0);
        if(s[0]=='('&&s[1]==')')
            dp[1] = 2;
        
        int res = dp[1];
        for(int i=2;i<len;++i){
            if(s[i]==')'){
                if(s[i-1]=='('){
                    dp[i] = dp[i-2]+2;
                    res = max(res,dp[i]);
                }
                else if(s[i-1]==')'&&i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='('){
                    dp[i] = dp[i-1] + 2 + (i-dp[i-1]-2>=0?dp[i-dp[i-1]-2]:0);
                    res = max(res,dp[i]);
                }
            }
        }
        
        return res;
    }
};
