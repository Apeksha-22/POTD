// Pythagorean Triplet



class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        if(arr.size() < 3) return false;
        unordered_map<long long, int>sq;
        for(int a : arr)
        sq[1LL * a * a]++;
        
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size();j++){
                int x = 1LL * ((arr[i] * arr[i]) + (arr[j] * arr[j]));
                if(sq[x] > 0) return true;
            }
        }
        return false;
    }
};
