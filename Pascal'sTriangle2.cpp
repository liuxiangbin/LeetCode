/*
	Given an index k, return the kth row of the Pascal's triangle.
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vi(rowIndex+1);
        if(rowIndex<0)
            return vi;
        
        int j;
        vector<int> vtmp(rowIndex);
        for(int i=0;i<=rowIndex;++i){
            for(j=0;j<=i;++j){
                if(j==0 || j==i)
                    vi[j] = 1;
                else
                    vi[j] = vtmp[j-1] + vtmp[j];
            }
            
            if(i<rowIndex)
                copy(vi.begin(),vi.begin()+j,vtmp.begin());
        }
        
        return vi;
    }
};