/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

/*
关于罗马数字的几条注意事项：
1、基本数字Ⅰ、X 、C 中的任何一个，自身连用构成数目，或者放在大数的右边连用构成数目，都不能超过三个；放在大数的左边只能用一个。
2、不能把基本数字V 、L 、D 中的任何一个作为小数放在大数的左边采用相减的方法构成数目；放在大数的右边采用相加的方式构成数目，只能使用一个。
3、V 和X 左边的小数字只能用Ⅰ。
4、L 和C 左边的小数字只能用X。
5、D 和M 左边的小数字只能用C。
*/

class Solution {
public:
    int romanToInt(string s) {
        int len = s.size();
        if(len==0)
            return 0;
            
        map<char,int> Rom2Dec;
        Rom2Dec['I'] = 1;
        Rom2Dec['V'] = 5;
        Rom2Dec['X'] = 10;
        Rom2Dec['L'] = 50;
        Rom2Dec['C'] = 100;
        Rom2Dec['D'] = 500;
        Rom2Dec['M'] = 1000;
            
        int res = Rom2Dec[s[0]];
        int cur, pre = res;
        for(int i=1;i<len;++i){
            cur = Rom2Dec[s[i]];
            if(pre < cur){
                res = res + cur - 2*pre; 
            }
            else{
                res += cur;
            }
            pre = cur;
        }
        
        return res;
    }
};