//Minimum Cost of ropes



class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(int x:arr)
        pq.push(x);
        
        int cst=0;
        while(pq.size()>1){
            int f=pq.top();
            pq.pop();
            int s=pq.top();
            pq.pop();
            
            cst += f+s;
            pq.push(f+s);
        }
        return cst;
    }
};
