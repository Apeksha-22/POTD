//Maximum Non-Adjacent Nodes Sum




/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    void dfs(Node* n, map<Node*, int>& pick, map<Node*, int>& skip) {
        if (!n) return;
        
        dfs(n->left, pick, skip);
        dfs(n->right, pick, skip);
        
        pick[n] += skip[n->left] + skip[n->right] + n->data;
        skip[n] += pick[n->left] + pick[n->right];
        
        if (skip[n] > pick[n]) pick[n] = skip[n];
    }

    int getMaxSum(Node* n) {
        map<Node*, int> pick, skip;
        pick[NULL] = skip[NULL] = 0;
        
        dfs(n, pick, skip);
        return max(pick[n], skip[n]);
    }
};
