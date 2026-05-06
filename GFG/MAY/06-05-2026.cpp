//Size of Binary Tree



/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void preorder(Node *node , int& cnt){
        if(!node) return;
        
        cnt++;
        preorder(node->left,cnt);
        preorder(node->right,cnt);
    }
    int getSize(Node* node) {
        int cnt = 0;
        preorder(node,cnt);
        return cnt;
    }
};
