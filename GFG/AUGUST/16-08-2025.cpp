// Form the Largest Number




class Solution {
  public:
    static bool func(string &a, string &b){
        return a+b > b+a;
    }
    string findLargest(vector<int> &nums) {
        // code here
        vector<string>arr;
        string ans = "";
        for(int x : nums)
        arr.push_back(to_string(x));
        
        sort(arr.begin(),arr.end(),func);
        
        for(auto & c : arr)
        ans += c;
        
        if(ans[0] == '0') return "0";
        return ans;
    }
};
