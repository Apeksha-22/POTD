//The Celebrity Problem




class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        stack<int>st;
        for(int i=n-1; i>=0; i--)
        st.push(i);
        
        while(st.size()>1){
            int fst=st.top();
            st.pop();
            int scnd=st.top();
            st.pop();
            if(mat[fst][scnd] == 0 && mat[scnd][fst] == 1) st.push(fst);
            else if(mat[fst][scnd] == 1 && mat[scnd][fst] == 0) st.push(scnd);
        }if(st.empty())
        return -1;
        int x=st.top();
        st.pop();
        
        int r=0,c=0;
        for(int i=0; i<n; i++){
            r += mat[x][i];
            c += mat[i][x];
        }
        return r==1 && c==n ? x : -1;
    }
}; 
