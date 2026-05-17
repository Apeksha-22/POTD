// Make the array beautiful



class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        vector<int>res;
        res.push_back(arr[0]);
        for(int i=1; i<arr.size(); i++){
            if(!res.empty()&&((arr[i] >= 0 && res.back() >= 0) || (arr[i] < 0 && res.back() < 0))){
                res.push_back(arr[i]);
            }else if(res.empty()){
                res.push_back(arr[i]);
            }else{
                res.pop_back();
            }
        }
        return res;
    }
};
