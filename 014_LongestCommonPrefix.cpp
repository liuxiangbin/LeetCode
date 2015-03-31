/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string res = "";
        
        int len = strs.size();
        int minlen = INT_MAX;
        for(int i=0;i<len;++i){
            int tmp = strs[i].size();
            if(minlen > tmp)
                minlen = tmp;
        }
        
        if(len==0||minlen==0)
            return res;
        
        for(int i=0;i<minlen;++i){
            for(int j=1;j<len;++j){
                if(strs[j][i]!=strs[0][i])
                    return res;
            }
            res += strs[0][i];
        }
        
        return res;
    }
};