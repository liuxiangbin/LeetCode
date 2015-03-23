/*
	Given numRows, generate the first numRows of Pascal's triangle.
*/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > vvi;
        if(numRows == 0)
            return vvi;
            
        for(int i=0;i<numRows;++i){
            vector<int> vi(i+1);
            for(int j=0;j<=i;++j){
                if(j==0 || j==i)
                    vi[j] = 1;
                else
                    vi[j] = vvi[i-1][j-1] + vvi[i-1][j];
            }
            vvi.push_back(vi);
        }
        
        return vvi;
    }
};