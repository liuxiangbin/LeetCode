class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
       double result = 0.0;
       if(m==0&&n==0)
            return result;
        
       vector<int> vc(m+n);
       int i=0,j=0,k=0;
       while(i<m || j<n){
           if(i>=m){
               for(;j<n;++j)
                   vc[k++] = B[j];
               break;
           }
           
           if(j>=n){
               for(;i<m;++i)
                    vc[k++] = A[i];
                break;
           }
           
           if(A[i]<=B[j]){
               vc[k++] = A[i++];
           }
           else{
               vc[k++] = B[j++];
           }
       }
       
       int tmp = (m+n)/2;
       if((m+n)%2==0){
           result = (vc[tmp-1]+vc[tmp])/2.0;
       }
       else{
           result = vc[tmp];
       }
       
       return result;
    }
};
