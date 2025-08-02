// 2561. Rearranging Fruits



class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int>tlfrq, frq1, frq2;
        vector<int>arr1,arr2;
        for(int x: basket1)tlfrq[x]++;
        for(int x: basket2)tlfrq[x]++;

        for(int x: basket1)frq1[x]++;
        for(int x: basket2)frq2[x]++;

        for(auto[x,y] : tlfrq){
            if(y %2 != 0) return -1;
            int total=y/2;
            int xtra1 = frq1[x] > total ? frq1[x] - total : 0;
            int xtra2 = frq2[x] > total ? frq2[x] - total : 0;
            
            for(int i=0; i<xtra1; i++) arr1.push_back(x);
            for(int i=0; i<xtra2; i++) arr2.push_back(x);
        }

        sort(arr1.begin(),arr1.end());
        sort(arr2.rbegin(),arr2.rend());

        int minele = min(
            *min_element(basket1.begin(), basket1.end()),
            *min_element(basket2.begin(), basket2.end())
        );

        long long cst = 0;

        for(int i=0; i<arr1.size(); i++){
            int a = arr1[i];
            int b = arr2[i];

            cst += min(min(a,b), 2 * minele);
        }
        return cst;
    }
};
