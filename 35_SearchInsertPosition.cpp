/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

class Solution {
public:
    int findLess(int A[],int n,int target)
    {
        int left = 0, right = n-1;
        int mid;
        while(left<=right){
            mid = left + (right - left )/2;
            if(A[mid]>=target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        
        return right;
    }

    int searchInsert(int A[], int n, int target) {
        int res = 0;
        
        if(n==0)
            return res;
        
        if(A[0] > target)
            return 0;
        if(A[n-1] < target)
            return n;
        
        res = findLess(A,n,target);
        
        return res+1;
    }
};