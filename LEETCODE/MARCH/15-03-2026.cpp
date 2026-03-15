// 1622. Fancy Sequence



class Fancy {
public:
    const long long MOD = 1000000007;
    vector<long long> arr;
    long long mul = 1, add = 0;

    long long modinv(long long x) {
        long long res = 1, p = MOD - 2;
        while (p) {
            if (p & 1) res = (res * x) % MOD;
            x = (x * x) % MOD;
            p >>= 1;
        }
        return res;
    }

    Fancy() {}

    void append(int val) {
        long long v = (val - add) % MOD;
        if (v < 0) v += MOD;
        v = (v * modinv(mul)) % MOD;
        arr.push_back(v);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= arr.size()) return -1;
        return (arr[idx] * mul + add) % MOD;
    }
};
