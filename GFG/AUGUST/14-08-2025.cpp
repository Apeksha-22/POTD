// Count Reverse Pairs



//using mergeSort

class Solution {
public:
    int countCrossPairs(vector<int>& arr, int l, int mid, int r) {
        int cnt = 0;
        int j = mid + 1;
        
        for (int i = l; i <= mid; i++) {
            while (j <= r && (long long)arr[i] > 2LL * arr[j]) {
                j++;
            }
            cnt += (j - (mid + 1));
        }
        return cnt;
    }

    void merge(vector<int>& arr, int s, int e, int mid) {
        int n1 = mid - s + 1;
        int n2 = e - mid;
        
        vector<int> left(n1), right(n2);
        
        for (int i = 0; i < n1; i++)
            left[i] = arr[s + i];
        for (int j = 0; j < n2; j++)
            right[j] = arr[mid + 1 + j];
        
        int i = 0, j = 0, k = s;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j])
                arr[k++] = left[i++];
            else
                arr[k++] = right[j++];
        }
        
        while (i < n1) arr[k++] = left[i++];
        while (j < n2) arr[k++] = right[j++];
    }

    int mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) return 0;
        int cnt = 0;
        int mid = l + (r - l) / 2;
        cnt += mergeSort(arr, l, mid);
        cnt += mergeSort(arr, mid + 1, r);
        cnt += countCrossPairs(arr, l, mid, r);
        merge(arr, l, r, mid);
        return cnt;
    }

    int countRevPairs(vector<int>& arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};


// using fenwick sort

struct Fenwick {
    vector<int> bit;
    int n;
    Fenwick(int n) : n(n), bit(n + 1, 0) {}
    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }
    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }
};

class Solution {
public:
    int countRevPairs(vector<int>& arr) {
        vector<long long> vals;
        for (long long x : arr) {
            vals.push_back(x);
            vals.push_back((x - 1) / 2);
        }

        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        auto getIndex = [&](long long x) {
            return (int)(lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1);
        };

        Fenwick fenw(vals.size());
        int cnt = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            cnt += fenw.query(getIndex((arr[i] - 1) / 2));
            fenw.update(getIndex(arr[i]), 1);
        }
        return cnt;
    }
};
