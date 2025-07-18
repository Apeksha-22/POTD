//2163. Minimum Difference in Sums After Removal of Elements


class Solution {
public:
    long long minimumDifference(vector<int>& A) {
        int n3 = A.size(), n = n3 / 3;
        vector<long long> left(n + 1);
        long long sumL = 0;

        priority_queue<int> maxL;
        for (int i = 0; i < n; ++i) {
            sumL += A[i];
            maxL.push(A[i]);
        }
        left[0] = sumL;

        for (int i = n; i < 2 * n; ++i) {
            sumL += A[i];
            maxL.push(A[i]);
            sumL -= maxL.top();
            maxL.pop();
            left[i - n + 1] = sumL;
        }

        long long sumR = 0;
        priority_queue<int, vector<int>, greater<int>> minR;
        for (int i = n3 - 1; i >= 2 * n; --i) {
            sumR += A[i];
            minR.push(A[i]);
        }

        long long res = left[n] - sumR;
        for (int i = 2 * n - 1; i >= n; --i) {
            sumR += A[i];
            minR.push(A[i]);
            sumR -= minR.top();
            minR.pop();
            res = min(res, left[i - n] - sumR);
        }

        return res;
    }
};
