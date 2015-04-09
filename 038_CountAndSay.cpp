/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string
*/

class Solution {
public:
    string countAndSay(int n) {
        string res;
        if(n<=0)
            return res;
            
        res += "1";
        string tmp;
        while(--n){
            tmp.clear();
            int cnt = 0, i = 0;
            char c = res[0];
            for(;i<res.size();++i){
                if(res[i]==c){
                    ++cnt;
                }
                else{
                    tmp += (to_string(cnt) + c);
                    c = res[i];
                    cnt = 1;
                }
            }
            if(cnt > 0){
                tmp += (to_string(cnt) + c);
            }
            res = tmp;
        }
        
        return res;
    }
};