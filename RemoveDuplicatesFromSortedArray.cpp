/*
	Given a sorted array, remove the duplicates in place such that each element
	appear only once and return the new length.
	Do not allocate extra space for another array, you must do this in place with 
	constant memory.
*/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        
        int cnt = 0;
        for(int i=1;i<n;++i){
            if(A[i]!=A[cnt])
                A[++cnt] = A[i];
        }
        
        return cnt+1;
    }
};