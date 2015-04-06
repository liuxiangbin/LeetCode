/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

//Solution 1: Recursion
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(p==NULL)
            return s==NULL;
        
        if(!*p)
            return !*s;
        
        if(*(p+1)=='*'){
            return (isMatch(s,p+2))||(*s&&(*s==*p||*p=='.')&&isMatch(s+1,p));
        }
        else{
            if(!*s) return false;
            if(*s==*p||*p=='.')
                return isMatch(s+1,p+1);
            else
                return false;
        }
    }
};

//Solution 2: Dynamic Programming
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int m = strlen(s);
        int n = strlen(p);
        
        bool matched[m+1][n+1];
        matched[0][0] = true;
        
        int i,j;
        for(i=0;i<m;++i)
            matched[i+1][0] = false;
        for(j=0;j<n;++j)
            matched[0][j+1] = j>0&&matched[0][j-1]&&p[j]=='*';
            
        for(i=0;i<m;++i)
            for(j=0;j<n;++j){
                if(p[j]=='*'){
                    matched[i+1][j+1] = (j>0&&matched[i+1][j-1])||matched[i+1][j]||(matched[i][j+1]&&j>0&&(s[i]==p[j-1]||p[j-1]=='.'));
                }
                else{
                    matched[i+1][j+1] = matched[i][j]&&(s[i]==p[j]||p[j]=='.');
                }
            }
            
        return matched[m][n];
    }
};