/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows <=1)
            return s;
            
        string result(s);
        int cnt1 = 2*nRows - 2, cnt2 = 0;
        int len = s.size();
        int i = 0,j = 0;
        for(;j<len;j+=cnt1)
            result[i++] = s[j];
        
        int col = 1;
        while(cnt1 > 2){
            cnt1 -= 2;
            cnt2 += 2;
            j = col;
            result[i++] = s[j];
            while(j < len){
                j += cnt1;
                if(j < len){
                    result[i++] = s[j];
                }
                else{
                    break;
                }
                
                j += cnt2;
                if(j < len){
                    result[i++] = s[j];
                }
                else{
                    break;
                }
            }
            ++col;
        }
        
        cnt1 -= 2;
        cnt2 += 2;
        j = col;
        for(;j<len;j+=cnt2)
            result[i++] = s[j];
        
        return result;
    }
};
