// Count Subarrays with given XOR



class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
         // code here
        unordered_map<int,int>mp;
        int XOR=0, count=0;
        
        for(int i=0;i<arr.size();i++){
            XOR = XOR xor arr[i];
            
            if(XOR==k) count++;
            
            if(mp.find(XOR xor k) != mp.end()) count +=mp[XOR xor k];
            
            mp[XOR]++;
        }return count;
    }
};
