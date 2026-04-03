// Print Diagonally


class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        // code here
        int n=mat.size();
        vector<int>res;
        for (int sum = 0; sum <= n + n - 2; sum++) {
            for (int i = 0; i < n; i++) {
                int j = sum - i;
                if (j >= 0 && j < n) {
                    res.push_back(mat[i][j]);
                }
            }
        }
        return res;
    }
};
