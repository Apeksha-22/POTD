//Missing Element in Range



class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        int n=high-low+1;
        vector<int>temp(n,-1),res;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=low && arr[i]<=high){
                temp[arr[i]-low]=arr[i];
            }
        }
        for(int i=0;i<n;i++){
            if(temp[i]==-1){
                res.push_back(i+low);
            }
        }
        return res;
    }
};
