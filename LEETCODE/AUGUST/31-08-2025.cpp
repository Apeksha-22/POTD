// 37. Sudoku Solver




class Solution {
public:
    bool check(int k, int i, int j, vector<vector<char>>& board){
        //check row
        char z = '0' + k;
        for(int x=0; x<9; x++){
            if(board[x][j] == z)
            return 0;
        }

        for(int x=0; x<9; x++){
            if(board[i][x] == z)
            return 0;
        }

        int c = i/3*3, d = j/3*3;

        for(int a=c; a<c+3; a++){
            for(int b=d; b<d+3; b++){
                if(board[a][b] == z)
                return 0;
            }
        }

        return 1;
    }
    bool find(int i, int j, vector<vector<char>>& board){
        if(i==9) return 1;

        if(j==9) return find(i+1, 0, board);
        if(board[i][j] != '.'){
            return find(i, j+1, board);
        }
        for(int k=1; k<10; k++){
            if(check(k, i, j, board)){
                board[i][j] = '0'+k;
                
                if(find(i, j+1, board))
                return 1;

                board[i][j] = '.';
            }
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
        find(0,0,board);
    }
};
