/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.
*/


//Solution 1
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.size();
        map<char,char> mc;
        set<char> sc;
        
        for(int i=0;i<len;++i){
            if(mc.find(s[i])==mc.end()){
                if(sc.find(t[i])==sc.end()){
                    mc[s[i]] = t[i];
                    sc.insert(t[i]);
                }
                else{
                    return false;
                }
            }
            else{
                if(mc[s[i]]!=t[i])
                    return false;
            }
        }
        
        return true;
    }
};

//Solution 2
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0};
        int m2[256] = {0};
        int len = s.size();
        
        for(int i=0;i<len;++i){
            if(m1[s[i]]!=m2[t[i]])  return false;
            m1[s[i]] = i+1;
            m2[t[i]] = i+1;
        }
        
        return true;
    }
};