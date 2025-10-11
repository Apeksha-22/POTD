//Construct Tree from Preorder & Postorder




/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* solve(vector<int> &pre, vector<int> &post, int st1, int ed1, int st2, int ed2){
        if(st1 == ed1)
            return new Node(pre[st1]);
        
        Node *root = new Node(pre[st1]);
        int ned1, ned2;
        for(int i=st1; i<=ed1; i++)
            if(pre[i] == post[ed2-1]) ned1 = i;
        for(int i=st2; i<=ed2; i++)
            if(post[i] == pre[st1+1]) ned2 = i;
        root->left = solve(pre, post, st1+1, ned1-1, st2, ned2);
        root->right = solve(pre, post, ned1, ed1, ned2+1 , ed2-1);
        return root;
    }
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        // code here
        int n = pre.size();
        return solve(pre, post, 0, n-1, 0, n-1);
    }
};
