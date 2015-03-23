/*
	Reverse digits of an integer.
*/
class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while(x){
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        
        return ret;
    }
};