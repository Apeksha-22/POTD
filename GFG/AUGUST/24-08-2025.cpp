// Minimum days to make M bouquets




class Solution {
  public:
    bool canMake(vector<int>&arr, int m, int k, int tar){
        int n=arr.size();
        int cnt=0, con=0;
        
        for(int i=0; i<n; i++){
            if(arr[i] <= tar)
            con++;
            
            if(con == k){
                cnt++;
                con=0;
            }
        }
        return cnt >= m;
    }
    int minDaysBloom(vector<int>& arr, int k, int m) {
        // Code here
        int n = arr.size();
        if((1LL*k*m) > n) return -1;
        int l = *min_element(arr.begin(),arr.end());
        int r = *max_element(arr.begin(),arr.end());
        int ans = -1;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(canMake(arr,m,k,mid)){
                ans = mid;
                r = mid-1;
            }else
            l = mid + 1;
        }
        return ans;
    }
};
