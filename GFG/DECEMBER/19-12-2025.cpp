// Bus Conductor


class Solution {
  public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        // code here
        sort(chairs.begin(),chairs.end());
        sort(passengers.begin(), passengers.end());
        int n=chairs.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum += abs(passengers[i]-chairs[i]);
        }
        return sum;
    }
};
