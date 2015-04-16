/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

//Solution 1:需要额外的存储空间
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        vector<vector<int> > tmp(matrix);
        
        int n = matrix.size();
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j){
                tmp[j][n-1-i] = matrix[i][j];
            }
          
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j){
                matrix[i][j] = tmp[i][j];
            } 
        
        return ;
    }
};

//Solution 2:无需额外的存储空间
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        
        int tmp;
        //首先顺时针旋转270
        for(int i=0;i<n;++i)
            for(int j=i+1;j<n;++j){
                tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
           
        //每行翻转180度
        for(int i=0;i<n;++i){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
        return ;
    }
};