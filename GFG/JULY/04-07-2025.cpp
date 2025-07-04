//Subarrays With At Most K Distinct Integers


class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int f=0,s=0;
        int cnt=0, count=0;
        unordered_map<int,int>freq;
        while(s<n){
            freq[arr[s]]++;
            if(freq[arr[s]] == 1)cnt++;
            
            while(cnt>k){
                freq[arr[f]]--;
                if(freq[arr[f]] == 0)cnt--;
                f++;
            }
            count += (s-f+1);
            s++;
        }
        return count;
    }
};
