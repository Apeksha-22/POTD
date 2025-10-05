// Rat in a Maze




class Solution {
  public:
    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};
    string x = "UDLR";
    bool valid(int i, int j, int n){
        if(i>=0 && j>=0 && i<n && j<n)
        return true;
        
        return false;
    }
    void findpath(vector<vector<int>>& maze,vector<vector<bool>>& vis, string& s, int n, vector<string>&res, int i, int j){
        if(i== n-1 && j==n-1){
            res.push_back(s);
            return;
        }vis[i][j] = 1;
        for(int k=0; k<4; k++){
            if(valid(i+row[k], j+col[k], n) && maze[i+row[k]][j+col[k]] == 1 && !vis[i+row[k]][j+col[k]]){
                vis[i+row[k]][j+col[k]] = 1;
                s.push_back(x[k]);
                findpath(maze,vis,s,n, res, i+row[k], j+col[k]);
                
                s.pop_back();
                vis[i+row[k]][j+col[k]] = 0;
            }
            
        }
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();

        vector<vector<bool>>vis(n,vector<bool>(n,0));
        vector<string>res;
        string s;
        if(maze[0][0] == 0 || maze[n-1][n-1] == 0)
        return res;
        findpath(maze,vis, s, n, res, 0, 0);
        sort(res.begin(), res.end());
        return res;
    }
};
