// Allocate Minimum Pages




class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k > arr.size()) return -1;
        int ans = -1;
        int l = *max_element(arr.begin(),arr.end());
        int r = accumulate(arr.begin(),arr.end(),0);
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            int cnt=1, pg=0;
            for(int i=0; i<arr.size(); i++){
                    pg += arr[i];
                if(pg > mid){
                    cnt++;
                    pg=arr[i];
                }
            }
            if(cnt > k) l = mid+1;
            else{
                ans = mid;
                r = mid-1;
            }
        }
        return ans;
    }
};
