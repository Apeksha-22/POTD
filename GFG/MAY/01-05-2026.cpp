// Kth Largest in a Stream



class Solution {
  public:
    vector<int> kthLargest(vector<int>arr, int k) {
        // code here
        int n = arr.size();
        vector<int>res(k-1,-1);
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(int i=0; i<=n; i++){
            if(pq.size() < k) pq.push(arr[i]);
            else{
                res.push_back(pq.top());
                if(arr[i] > pq.top()){
                    pq.pop();
                    pq.push(arr[i]);
                }
            }
        }
        return res;
    }
};
