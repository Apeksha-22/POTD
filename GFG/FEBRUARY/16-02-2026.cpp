// User function Template for C++
//Meeting Rooms



class Solution {
public:
    bool canAttend(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        int prevEnd = arr[0][1];
        
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i][0] < prevEnd) {
                return false;
            }
            prevEnd = arr[i][1];
        }
        return true;
    }
};
