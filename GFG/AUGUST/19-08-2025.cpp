// Farthest Smaller Right



class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>suffmin(n), ans(n,-1);
        
        suffmin[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){
            suffmin[i] = min(arr[i], suffmin[i+1]);
        }
        
        for(int i=0; i<n; i++){
            
            int s = i+1, e=n-1;
            
            while(s<=e){
                int mid = s+(e-s)/2;
                
                if(suffmin[mid] < arr[i]){
                    ans[i] = mid;
                    s = mid + 1;
                }else{
                    e = mid - 1;
                }
            }
        }
        return ans;
    }
};


//2nd Method

class Solution {
  public:
    vector<int> farMin(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<pair<int, int>> tmp(n);
        for(int i = 0; i < n; i++) tmp[i] = {arr[i], i};
        sort(tmp.begin(), tmp.end());
        vector<int> ans(n, -1);
        for(int i = 0, m = -1; i < n; i++) {
            if(m > tmp[i].second) ans[tmp[i].second] = m;
            m = max(m, tmp[i].second);
        }
        return ans;
    }
};
