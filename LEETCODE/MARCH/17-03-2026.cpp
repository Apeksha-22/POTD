// 1727. Largest Submatrix With Rearrangements



class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 1)
                mat[i][j] += mat[i-1][j];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>row = mat[i];
            sort(row.begin(),row.end(), greater<int>());

            for(int j=0; j<m; j++)
            ans = max(ans, row[j]*(j+1));
        }
        return ans;
    }
};
