//Segregate 0s and 1s



class Solution {
  public:
    void segregate0and1(vector<int> &nums) {
        // code here
        int n =nums.size();
        int lastzero = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                swap(nums[i], nums[lastzero]);
                lastzero++;
            }
        }
    }
};
