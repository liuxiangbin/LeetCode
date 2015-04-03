/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

//Solution 1:O(N^2)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int slen = s.size();
        if(slen <= 1)
            return slen;
            
        int maxlen = 0;
        int i=0,j=1,k=0,len=0;  
        
        while(j < slen){
            for(k=i;k<j;++k){
                if(s[k]==s[j]){
                    len = j-i;
                    if(len > maxlen)
                        maxlen = len;
                    i = k+1;
                    break;
                }
            }
            ++j;
        }
        
        len = j-i;
        if(len > maxlen)
             maxlen = len;
        
        return maxlen;
    }
};

//Solution 2:O(N)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int slen = s.size();
        if(slen <= 1)
            return slen;
            
        int maxlen = 0;
        int begin = 0;
        
        map<char,int> map;
        int i;
        for(i=0;i<slen;++i){
            if(map.find(s[i])!=map.end()&&map[s[i]]>=begin){
                int tmp = i - begin;
                maxlen = tmp>maxlen?tmp:maxlen;
                begin = map[s[i]] + 1;
            }
            
            map[s[i]] = i;
        }
        
        maxlen = (i-begin)>maxlen?i-begin:maxlen;
        
        return maxlen;
    }
};