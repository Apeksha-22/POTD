// 3197. Find the Minimum Area to Cover All Ones II




class Solution {
    int getRectArea(vector<vector<int>> &mat, int top, int bottom, int left, int right) {
        int minRow = mat.size(), maxRow = 0;
        int minCol = mat[0].size(), maxCol = 0;
        for (int i = top; i <= bottom; i++) {
            for (int j = left; j <= right; j++) {
                if (mat[i][j] == 1) {
                    minRow = min(minRow, i);
                    minCol = min(minCol, j);
                    maxRow = max(maxRow, i);
                    maxCol = max(maxCol, j);
                }
            }
        }
        return minRow <= maxRow ? (maxRow - minRow + 1) * (maxCol - minCol + 1) : INT_MAX / 3;
    }

    vector<vector<int>> rotateGrid(vector<vector<int>> &mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<vector<int>> rotated(cols, vector<int>(rows));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                rotated[cols - j - 1][i] = mat[i][j];
            }
        }
        return rotated;
    }

    int computeMinSum(vector<vector<int>> &mat) {
        int rows = mat.size(), cols = mat[0].size();
        int best = rows * cols;

        // L-shape partitions
        for (int i = 0; i + 1 < rows; i++) {
            for (int j = 0; j + 1 < cols; j++) {
                best = min(best,
                           getRectArea(mat, 0, i, 0, cols - 1) +
                           getRectArea(mat, i + 1, rows - 1, 0, j) +
                           getRectArea(mat, i + 1, rows - 1, j + 1, cols - 1));

                best = min(best,
                           getRectArea(mat, 0, i, 0, j) +
                           getRectArea(mat, 0, i, j + 1, cols - 1) +
                           getRectArea(mat, i + 1, rows - 1, 0, cols - 1));
            }
        }

        // Pure horizontal partitions
        for (int i = 0; i + 2 < rows; i++) {
            for (int j = i + 1; j + 1 < rows; j++) {
                best = min(best,
                           getRectArea(mat, 0, i, 0, cols - 1) +
                           getRectArea(mat, i + 1, j, 0, cols - 1) +
                           getRectArea(mat, j + 1, rows - 1, 0, cols - 1));
            }
        }
        return best;
    }

public:
    int minimumSum(vector<vector<int>> &grid) {
        auto rotated = rotateGrid(grid);
        return min(computeMinSum(grid), computeMinSum(rotated));
    }
};
