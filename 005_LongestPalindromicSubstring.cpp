/*Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

class Solution {
public:
    string expandFromCenter(string s,int len,int begin,int end)
    {
        while(begin>=0&&end<len&&s[begin]==s[end]){
            --begin;
            ++end;
        }
        
        return s.substr(begin+1,end-begin-1);
    }

    string longestPalindrome(string s) {
        int len = s.size();
        if(len <= 1)
            return s;
            
        string res(s.substr(0,1));
        for(int i=0;i<len-1;++i){
            string tmp = expandFromCenter(s,len,i,i);
            if(tmp.size()>res.size())
                res = tmp;
                
            tmp = expandFromCenter(s,len,i,i+1);
            if(tmp.size()>res.size())
                res = tmp;
        }
        
        return res;
    }
};