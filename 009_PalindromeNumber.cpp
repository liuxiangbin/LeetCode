/*
Determine whether an integer is a palindrome. Do this without extra space.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        else if(x < 10)
            return true;
            
        int rx = 0 , oldx = x;
        while(x!=0){
            rx = 10*rx + x%10;
            x /= 10;
        }
        
        if(oldx==rx)
            return true;
        else
            return false;
    }
};