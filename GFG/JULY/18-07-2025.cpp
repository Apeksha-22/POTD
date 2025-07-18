//LCM Triplet


class Solution {
public:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return (a * b) / gcd(a, b);
    }

    long long lcmTriplets(int n) {
        long long maxLCM = 0;
        for (int i = n; i >= max(1, n - 7); --i) {
            for (int j = i; j >= max(1, n - 7); --j) {
                for (int k = j; k >= max(1, n - 7); --k) {
                    long long curr = lcm(lcm(i, j), k);
                    maxLCM = max(maxLCM, curr);
                }
            }
        }

        return maxLCM;
    }
};
