/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int lenOfNeedle = strlen(needle);
        if(lenOfNeedle==0)
            return 0;
            
        int lenOfHaystack = strlen(haystack);
        if(lenOfHaystack < lenOfNeedle)
            return -1;
        
        int len = lenOfHaystack-lenOfNeedle;
        int i,j;
        for(i=0;i<= len;++i){
            for(j=0;j<lenOfNeedle;++j){
                if(*(haystack+i+j)!=*(needle+j))
                    break;
            }
            if(j==lenOfNeedle)
                return i;
        }
        
        return -1;
    }
};