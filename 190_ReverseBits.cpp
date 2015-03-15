/*
Reverse bits of a given 32 bits unsigned integer.
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t x = n;
        
        for(int i=0;i<16;++i){
            int left = (x>>i)& 1;
            int right = (x>>(31-i))&1;
            if(left!= right){
                x ^= 1<<i;
                x ^= 1<<(31-i);
            }
        }
        
        return x;
    }
};