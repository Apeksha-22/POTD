// Subarrays with sum K

class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int>prfxsm;
        prfxsm[0]=1;
        int curr=0, count=0;
        for(int i=0; i<arr.size(); i++){
            curr += arr[i];
            
            if(prfxsm.find(curr-k) != prfxsm.end()){
                count += prfxsm[curr-k];
            }
            prfxsm[curr]++;
        }
        
        return count;
    }
};
