//Remove BST keys outside given range




/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* findMax(Node* root) {
        while (root && root->right)
            root = root->right;
        return root;
    }

    Node* deleteNode(Node* root, int key) {
        if (!root) return NULL;
        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left && !root->right) {
                delete root;
                return NULL;
            } else if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else {
                Node* temp = findMax(root->left);
                root->data = temp->data;
                root->left = deleteNode(root->left, temp->data);
            }
        }
        return root;
    }

    Node* removekeys(Node* root, int l, int r) {
        if (!root) return NULL;
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);
        if (root->data < l)
            return removekeys(root->right, l, r);
        if (root->data > r)
            return removekeys(root->left, l, r);
        return root;
    }
};
