// Count X in Range of a Sorted Array



class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto it : queries)
        {
            int l = upper_bound(arr.begin() + it[0], arr.begin() + it[1] + 1, it[2]-1) - arr.begin();
            int r = upper_bound(arr.begin() + it[0], arr.begin() + it[1] + 1, it[2]) - arr.begin();
            res.push_back(r-l);
        }
        return res;
    }
};
