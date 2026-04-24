// Buildings with Sunlight



class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        int n = arr.size();
        int count = 1;
        int maxHeight = arr[0];
        
        for(int i = 1; i < n; i++) {
            if(arr[i] >= maxHeight) {
                count++;
                maxHeight = arr[i];
            }
        }
        return count;
    }
};
