class Solution {
  public:
  void func(vector<vector<int>>& res, vector<int>&temp, int num, int tar, int sz){
      if(temp.size() > sz) return;
      if(tar < 0)return;
      if(temp.size() == sz && tar == 0){
          res.push_back(temp);
          return;
      }
      if(num > 9) return;
      func(res,temp,num+1,tar,sz);
      temp.push_back(num);
      func(res, temp, num+1, tar-num, sz);
      temp.pop_back();
  }
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<vector<int>>res;
        vector<int>temp;
        if(n>1 && n == k) return {};
        func(res,temp,1,n,k);
        return res;
    }
};
