// 3477. Fruits Into Baskets II



class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size(),cnt=0,count=0;
        for(int frts : fruits){
            cnt=1;
            for(int i=0; i<n; i++){
                if(frts <= baskets[i]){
                    cnt=0;
                    baskets[i] = 0;
                    break;
                }
            }
            count += cnt;
        }
        return count;
    }
};
