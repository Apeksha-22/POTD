// Make Matrix Beautiful


class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> rowSum(n, 0);
        vector<int> colSum(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                rowSum[i] += mat[i][j];
                colSum[j] += mat[i][j];
            }
        }
        int target = 0;
        for(int i = 0; i < n; i++) {
            target = max(target, rowSum[i]);
            target = max(target, colSum[i]);
        }
        int rowOps = 0, colOps = 0;
        for(int i = 0; i < n; i++) {
            rowOps += (target - rowSum[i]);
        }
        for(int j = 0; j < n; j++) {
            colOps += (target - colSum[j]);
        }
        return max(rowOps, colOps);
    }
};
