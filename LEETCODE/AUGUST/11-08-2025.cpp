// 2438. Range Product Queries of Powers



class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9+7;
        vector<int>power;
        int sum=0;
        for(int i=0; i<31; i++){
            if(n & (1 << i))
            power.push_back(1LL << i);
        }
        int m = queries.size();
        vector<int>res(m);
        for(int i=0;i<m; i++){
            long long p=1;
            for(int j=queries[i][0]; j<=queries[i][1]; j++){
                p = (p * power[j]) % MOD ;
            }
            res[i] = p;
        }
        return res;
    }
};
