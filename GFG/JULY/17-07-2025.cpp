//Power of k in factorial of n

class Solution {
public:
    map<int, int> Prims(int k) { //primes find karne ke liye
        map<int, int> f;
        for (int i = 2; i * i <= k; i++) {
            while (k % i == 0) {
                f[i]++;
                k /= i;
            }
        }
        if (k > 1) f[k]++;
        return f;
    }

    int powInFact(int n, int p) {
        int cnt = 0;
        while (n > 0) {
            cnt += n / p;
            n /= p;
        }
        return cnt;
    }

    int maxKPower(int n, int k) { // it's main function
        map<int, int> pf = Prims(k);
        int ans = INT_MAX;
        for (map<int, int>::iterator it = pf.begin(); it != pf.end(); ++it) {
            int p = it->first;
            int f = it->second;
            int c = powInFact(n, p);
            ans = min(ans, c / f);
        }
        return ans;
    }
};
