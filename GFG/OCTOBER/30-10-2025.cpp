//Replace O's with X's




class Solution {
public:
    void fill(vector<vector<char>>& grid) {
        if (grid.empty()) return;
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;

        auto pushIfO = [&](int r, int c){
            if (r>=0 && r<n && c>=0 && c<m && grid[r][c]=='O') {
                grid[r][c] = '#';
                q.push({r,c});
            }
        };

        for (int i = 0; i < n; ++i) {
            pushIfO(i, 0);
            pushIfO(i, m-1);
        }
        for (int j = 0; j < m; ++j) {
            pushIfO(0, j);
            pushIfO(n-1, j);
        }

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty()) {
            auto [r,c] = q.front(); q.pop();
            for (auto &d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='O') {
                    grid[nr][nc] = '#';
                    q.push({nr,nc});
                }
            }
        }

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                grid[i][j] = (grid[i][j]=='#') ? 'O' : (grid[i][j]=='O' ? 'X' : grid[i][j]);
    }
};
