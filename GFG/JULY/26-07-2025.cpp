// Majority Element II



class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int>res;
        unordered_map<int,int>freq;
        for(int x : arr)
        freq[x]++;
        
        for(auto x : freq){
            if(x.second > n/3)
            res.push_back(x.first);
        }
        sort(res.begin(),res.end());
        return res;
    }
};
