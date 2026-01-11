// 85. Maximal Rectangle



class Solution {
public:
    int rectangle(vector<int>& h) {
        int n = h.size(), ans = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && h[st.top()] > h[i]) {
                int idx = st.top();
                st.pop();
                if (!st.empty())
                    ans = max(ans, h[idx] * (i - st.top() - 1));
                else
                    ans = max(ans, h[idx] * i);
            }
            st.push(i);
        }
        while (!st.empty()) {
            int idx = st.top();
            st.pop();
            if (!st.empty())
                ans = max(ans, h[idx] * (n - st.top() - 1));
            else
                ans = max(ans, h[idx] * n);
        }
        return ans;
    }
	int maximalRectangle(vector<vector<char>>& mat) {
    	int rws = mat.size();
    	int col = mat[0].size();
    	int ans = 0;
    	vector<int> h(col, 0);
    	for (int i = 0; i < rws; i++) {
        	for (int j = 0; j < col; j++) {
            	if (mat[i][j] == '0')
                	h[j] = 0;
            	else
          	    	h[j] += 1;
        	}
        	ans = max(ans, rectangle(h));
    	}
    	return ans;
	}
};
