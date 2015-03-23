/*
	Given a non-negative number represented as an array of digits,plus one to the number.
	The digits are stored such that the most significant digit is at the head of the list.
*/
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int len = digits.size();
        if(len == 0)
            return digits;
            
        if(digits[len-1]<9){
            digits[len-1] += 1;
            return digits;
        }
        else{
            digits [len-1] = 0;
            int carry = 1;
            int i;
            for(i=len-2;i>=0;--i){
                int tmp = digits[i]+carry;
                digits[i] = (tmp) % 10;
                carry = (tmp)/10;
                if(carry == 0)
                    break;
            }
            
            if(i==-1 && carry==1)
                digits.insert(digits.begin(),carry);
                
            return digits;
        }
    }
};