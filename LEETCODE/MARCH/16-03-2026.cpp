// 1878. Get Biggest Three Rhombus Sums in a Grid



class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        set<int, greater<int>>s;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                s.insert(grid[i][j]);

                int mxk = min({i,j,m-j-1,n-1-i});
                
                for(int k=1; k<=mxk; k++){
                    int sum=0;

                    for(int t=0; t<k; t++) sum += grid[i-k+t][j+t];
                    for(int t=0; t<k; t++) sum += grid[i-t+k][j-t];
                    for(int t=0; t<k; t++) sum += grid[i+t][j+k-t];
                    for(int t=0; t<k; t++) sum += grid[i-t][j-k+t];

                    s.insert(sum);
                }
            }
        }
        vector<int>ans;
        for(int i: s){
            ans.push_back(i);
            if(ans.size() == 3)break;
        }
        return ans;
    }
};
