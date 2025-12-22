// Row with max 1s



class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();
        int mini = INT_MAX;
        int ind = -1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] == 1){
                    if(j < mini){
                        mini = j;
                        ind = i;
                    }
                    break;
                }
            }
        }
        return ind;
    }
};
