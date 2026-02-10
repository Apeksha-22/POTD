// Koko Eating Bananas



class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int n= arr.size(), ans=0;
        int left=1, right=*max_element(arr.begin(),arr.end());
        while(left<=right){
            int mid= left +(right-left)/2;
            int hr=0;
            for(int i= 0; i<n; i++){
                hr += (arr[i]/mid);
                if(arr[i]%mid != 0) hr++;
            }
            if(hr <= k){
                ans = mid;
                right = mid-1;
            }else{
                
                left= mid + 1;
            }
            
        }
        return ans;
    }
};
