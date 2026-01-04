// Sort 0s, 1s and 2s



class Solution {
  public:
    void sort012(vector<int>& arr) {
        int s = 0;
        for(int i = 0;i<arr.size();i++){
            if(arr[i]==0){
                swap(arr[i], arr[s]);
                s++;
            }
        }
        for(int i = s;i<arr.size();i++){
            if(arr[i]==1){
                swap(arr[i], arr[s]);
                s++;
            }
        }
    }
};
