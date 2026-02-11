// Equalize the Towers



class Solution {
  public:
    int getCost(int target, vector<int>& heights, vector<int>& cost){
        int total=0;
        for(int i=0; i<heights.size(); i++){
            total += abs(heights[i] - target) * cost[i];
        }
        return total;
    }
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n=heights.size(), res = 0;
        int left =*min_element(heights.begin(), heights.end()), right = *max_element(heights.begin(), heights.end());
        while(left<right){
            int mid = left + (right -left)/2;
            int cost1 = getCost(mid, heights, cost);
            int cost2 = getCost(mid+1, heights, cost);
            
            if(cost1 > cost2){
                left = mid + 1;
            }else
                
                right = mid;
        }
        return getCost(left, heights, cost);
    }
};
