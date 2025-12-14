// 2D Submatrix Sum Queries




class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        // code here
        int row=mat.size(),col=mat[0].size();
        vector<vector<int>>prefix=mat;
        for(int i=0;i<row;i++){
            for(int j=1;j<col;j++){
                prefix[i][j]=prefix[i][j-1]+mat[i][j];
            }
        }
        
        for(int j=0;j<col;j++){
            for(int i=1;i<row;i++){
                prefix[i][j]+=prefix[i-1][j];
            }
        }

        vector<int>ans;
        for(auto q:queries){
            int r1=q[0],c1=q[1],r2=q[2],c2=q[3];
            int total=prefix[r2][c2];
            int s1=(c1-1>=0) ? prefix[r2][c1-1] : 0;
            int s2=(r1-1>=0) ? prefix[r1-1][c2] : 0;
            int s3=(r1-1>=0 && c1-1>=0) ? prefix[r1-1][c1-1] : 0;
            ans.push_back(total-(s1+s2) + s3);
        }
        return ans;
    }
};
