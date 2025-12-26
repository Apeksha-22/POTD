// Kth Missing Positive Number in a Sorted Array



class Solution {
    public:
    int kthMissing(vector<int>& arr, int k) {
        // code here
        
        int left = 0;
        int right = arr.size() - 1;
        int index = -1;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            
            if((arr[mid] - mid - 1) >= k){
                index = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        
        if(index == -1){
            return k + right + 1;
        }
        return index + k;
    }
};
