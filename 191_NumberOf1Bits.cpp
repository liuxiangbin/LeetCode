/*Write a function that takes an unsigned integer and 
returns the number of ’1' bits it has (also known as 
the Hamming weight).
*/

//Solution 1
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        
        while(n){
            if(n&1){
                ++result;
            }
            n >>= 1;
        }
        
        return result;
    }
};

//Solution 2
class Solution {
public:
    int hammingWeight(uint32_t n) {
        if(n==0)
            return 0;

        int result = 1;
        while(n &= (n-1)){
            ++result;
        }
        
        return result;
    }
};

