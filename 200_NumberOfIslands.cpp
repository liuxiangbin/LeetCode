/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/

class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    void dfs(int row,int col,int rows,int cols,vector<vector<char> > &grid,vector<vector<bool> > &visited)
    {
        visited[row][col] = true;
        int r,c;
        for(int i=0;i<4;++i){
            r = row + dx[i];
            c = col + dy[i];
            if(r>=0&&r<rows&&c>=0&&c<cols&&grid[r][c]=='1'&&!visited[r][c])
                dfs(r,c,rows,cols,grid,visited);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int rows = grid.size();
        if(rows==0)
            return res;
            
        int cols = grid[0].size();
        vector<vector<bool> > visited(rows,vector<bool>(cols,false));
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(grid[i][j]=='1'&&!visited[i][j]){
                    ++ res;
                    dfs(i,j,rows,cols,grid,visited);
                }
            }
        }
        
        return res;
    }
};