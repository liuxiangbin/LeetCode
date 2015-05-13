/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

class Solution {
public:
    
    void spiralOrderAux(vector<vector<int> > &matrix,int startrow,int endrow,int startcol,int endcol,vector<int> &res)
    {
        if(startrow >= endrow || startcol >= endcol)
            return ;
            
        int i,j;
        for(j=startcol;j<endcol;++j)
            res.push_back(matrix[startrow][j]);
        for(i=startrow+1;i<endrow;++i)
            res.push_back(matrix[i][endcol-1]);
        if(endrow-1 > startrow){
            for(j=endcol-2;j>=startcol;--j)
                res.push_back(matrix[endrow-1][j]);
        }
        if(startcol < endcol-1){
            for(i=endrow-2;i>startrow;--i)
                res.push_back(matrix[i][startcol]);
        }
            
        spiralOrderAux(matrix,startrow+1,endrow-1,startcol+1,endcol-1,res);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rows = matrix.size();
        if(rows == 0)
            return res;
            
        int cols = matrix[0].size();
        spiralOrderAux(matrix,0,rows,0,cols,res);
        
        return res;
    }
};