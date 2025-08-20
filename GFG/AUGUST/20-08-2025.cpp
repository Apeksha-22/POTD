// Search in fully rotated sorted 2D matrix




class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        int l = 0, r = n * m - 1;

        while (l <= r) {
            int mid = l + (r - l)/2;
            int row = mid / m;
            int col = mid % m;
            int midVal = mat[row][col];

            if (midVal == x) return true;

            int lRow = l / m, lCol = l % m;
            int rRow = r / m, rCol = r % m;
            
            //left side or right side mein value ki range target se chhoti ya badi h
            int lVal = mat[lRow][lCol];
            int rVal = mat[rRow][rCol];
            
            if (lVal <= midVal) {
                if (lVal <= x && x < midVal)
                r = mid - 1;
                else
                l = mid + 1;
            } else {
                if (midVal < x && x <= rVal) l = mid + 1;
                else r = mid - 1;
            }
        }

        return false;
    }
};
