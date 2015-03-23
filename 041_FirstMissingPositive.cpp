/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

//This Solution comes from here:
//http://www.cnblogs.com/AnnieKim/archive/2013/04/21/3034631.html
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int res = n + 1;
        
        for(int i=0;i<n;++i){
            while(A[i]>0 && A[i]<=n && A[A[i]-1] != A[i]){
                swap(A[A[i]-1],A[i]);
            }
        }
        
        for(int i=0;i<n;++i){
            if(A[i]!= i+1){
                res = i+1;
                break;
            }
        }
            
        return res;
    }
};


//对于无重复元素的情况有如下解法
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int res;
        
        int maxnum = 0,sum = 0;
        for(int i=0;i<n;++i){
            if(A[i] > 0){
                sum += A[i];
                if(maxnum < A[i])
                    maxnum = A[i];
            }
        }
        
        int maxsum = maxnum*(maxnum+1)/2;
        if(sum == maxsum)
            res = maxnum + 1;
        else
            res = maxsum - sum;
            
        return res;
    }
};