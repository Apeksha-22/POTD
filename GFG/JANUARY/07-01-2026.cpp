// Count distinct elements in every window



class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        vector<int> res;
        unordered_map<int, int> mp;
        int n=arr.size();
        int count=0;
        for(int i=0;i<k;i++){
            mp[arr[i]]++;
        }
        res.push_back(mp.size());
        
        int j=0;
        for(int i=k;i<n;i++){
            mp[arr[j]]--;
            if(mp[arr[j]]==0)mp.erase(arr[j]);
            j++;
            mp[arr[i]]++;
            
            res.push_back(mp.size());
        }
        return res;
    }
};
