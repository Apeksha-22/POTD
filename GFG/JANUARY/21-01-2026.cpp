//Stock span problem



class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        int n=arr.size();
        stack<int>st;
        vector<int>res(n,1);
        
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            if(!st.empty())
            res[i] = i-st.top();
            else
            res[i] = i+1;
            
            st.push(i);
        }
        return res;
    }
};
