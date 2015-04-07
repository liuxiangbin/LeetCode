/*
Given an integer, convert it to a roman numeral.

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
    string intToRoman(int num) {
        string res;
        if(num < 1)
            return res;
            
        string roman[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int dec[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        
        while(num > 0){
            int i = 0;
            while(num<dec[i])
                ++i;
            
            res += roman[i];
            num -= dec[i];
        }
        
        return res;
    }
};