/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
    int findLess(int A[],int n,int target)
    {
    	int left = 0,right = n - 1;
    	int mid;
    	while(left<=right){
    		mid = left + (right-left)/2;
    		if(A[mid]>=target)
    			right = mid - 1;
    		else
    			left = mid + 1 ;
    	}
    
    	return right;
    }
    
    int findGreat(int A[],int n,int target)
    {
    	int left = 0,right = n - 1;
    	int mid;
    	while(left<=right){
    		mid = left + (right-left)/2;
    		if(A[mid]<=target)
    			left = mid + 1;
    		else
    			right = mid - 1;
    	}
    
    	return left;
    }

    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res(2,-1);
        
        if(n==0)
            return res;
            
    	int left = findLess(A,n,target);
    	int right = findGreat(A,n,target);
    	if(left+1 == right)
    		return res;
    	res[0] = left+1;
    	res[1] = right-1;
    	return res;
    }
};