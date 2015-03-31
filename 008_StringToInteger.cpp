/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*/

class Solution {
public:
    int atoi(string str) {
        if(str.empty())
            return 0;
        
        long long res = 0;
        int i=0,len=str.size();
        while(i<len&&str[i]==' ') 
            ++i;
            
        int sign = 1;
        if(str[i]=='-'){
            sign = -sign;
        }
        
        if(str[i]=='-'||str[i]=='+'){
            ++i;
            if(str[i]=='-'||str[i]=='+')
                return 0;
        }
        
        while(i<len){
            if(isdigit(str[i])){
                res = 10*res + str[i]-'0';
                if(sign*res > INT_MAX)
                    return INT_MAX;
                if(sign*res < INT_MIN)
                    return INT_MIN;
            }
            else
                break;
            ++i;
        }
        
        return sign*res;
    }
};