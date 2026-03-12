// Minimum K Consecutive Bit Flips


class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        vector<int>flip(n,0);
        int cnt=0;
        int curr=0;
        for(int i=0; i<n; i++){
            if(i>=k)
            curr ^= flip[i-k];
            
            if(arr[i] == curr){
                if(i+k>n) return -1;
                flip[i] = 1;
                curr ^= 1;
                cnt++;
            }
        }
        return cnt;
    }
};
