/*
Rotate an array of n elements to the right by k steps.
*/

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k %= n;
        
        reverse(nums,nums+n-k);
        reverse(nums+n-k,nums+n);
        reverse(nums,nums+n);
    }
};