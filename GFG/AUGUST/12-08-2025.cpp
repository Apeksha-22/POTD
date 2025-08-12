// Shop in Candy Store



class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        sort(prices.begin(),prices.end());
        int n=prices.size();
        int mine = 0, maxe = 0;
        int i=0, j=n-1;
        while(i<n && i<=j){
            mine += prices[i];
            j -= k;
            i++;
        }
        
        i=0, j=n-1;
        while(i<n && i<=j){
            maxe += prices[j];
            j--;
            i += k;
        }
        return {mine, maxe};
    }
};
