// 1200. Minimum Absolute Difference



class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int diff=INT_MAX;
        vector<vector<int>>res;
        for(int i=0;i<n-1;i++){
            if(arr[i+1] - arr[i] < diff){
                res.clear();
                diff=arr[i+1]-arr[i];
            }else if(arr[i+1]-arr[i]>diff) continue;
            res.push_back({arr[i],arr[i+1]});
        }
        return res;
    }
};
