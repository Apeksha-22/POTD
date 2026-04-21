// Mean of range in array



class Solution {
public:
    vector<int> findMean(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        
        vector<int> pre(n);
        pre[0] = arr[0];

        for(int i = 1; i < n; i++)
            pre[i] = pre[i-1] + arr[i];

        vector<int> ans;

        for(auto &q : queries){
            int l = q[0];
            int r = q[1];

            int sum = pre[r] - (l ? pre[l-1] : 0);
            ans.push_back(sum / (r - l + 1));
        }
        return ans;
    }
};
