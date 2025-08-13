// Tywin's War Strategy




class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        int n=arr.size();
        int cnt=0,ans=0;
        vector<int>temp;
        for(int x : arr){
            if(x % k == 0){
                temp.push_back(0);
            }else
            temp.push_back(k-(x%k));
        }
        sort(temp.begin(),temp.end());
        for(int i=0; i<(n+1)/2; i++){
            ans += temp[i];
        }
        return ans;
    }
};
