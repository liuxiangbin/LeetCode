/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.
*/

class Solution {
public:
    bool isValid(vector<int> &cnt)
    {
        for(int i=1;i<10;++i){
            if(cnt[i] > 1)
                return false;
        }
        
        return true;
    }

    bool isValidSudoku(vector<vector<char> > &board) {
        vector<int> cnt(10,0);
        
        for(int i=0;i<9;++i){
            fill_n(cnt.begin(),10,0);
            
            for(int j=0;j<9;++j){
                if(board[i][j]!='.')
                    ++cnt[board[i][j]-'0'];
            }
            
            if(!isValid(cnt))
                return false;
        }
        
        for(int j=0;j<9;++j){
            fill_n(cnt.begin(),10,0);
            
            for(int i=0;i<9;++i){
                if(board[i][j]!='.')
                    ++cnt[board[i][j]-'0'];
            }
            
            if(!isValid(cnt))
                return false;
        }
        
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                fill_n(cnt.begin(),10,0);
                for(int k=0;k<3;++k){
                    if(board[i+k][j]!='.')
                        ++cnt[board[i+k][j]-'0'];
                    if(board[i+k][j+1]!='.')
                        ++cnt[board[i+k][j+1]-'0'];
                    if(board[i+k][j+2]!='.')
                        ++cnt[board[i+k][j+2]-'0'];
                }
                
                if(!isValid(cnt))
                    return false;
            }
        }
        
        return true;
    }
};