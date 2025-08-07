// Difference Check



class Solution {
  public:
    int second(string & x){
        int h = stoi(x.substr(0,2));
        int m = stoi(x.substr(3,2));
        int s = stoi(x.substr(6,2));
        return h*3600 + m * 60 + s;
    }
    int minDifference(vector<string> &arr) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        int minDiff = 86400;
    
        for (int i = 0; i < arr.size(); i++) {
            int curr = second(arr[i]);
            int next = second(arr[(i + 1) % n]);
            int diff = abs(curr - next);
            diff = min(diff, 86400 - diff);
            minDiff = min(minDiff, diff);
        }
        return minDiff;
    }
};
