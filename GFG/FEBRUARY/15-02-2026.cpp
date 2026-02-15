// Chocolate Distribution Problem



class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        int n=a.size(),ans=INT_MAX;
        sort(begin(a),end(a));
        
        int i=0,j=m-1;
        while(j<n) ans=min(ans,a[j++]-a[i++]);
        
        return ans;
    }
};
