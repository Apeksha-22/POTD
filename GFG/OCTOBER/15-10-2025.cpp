// k-th Smallest in BST




/*Complete the function below

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int kthSmallest(Node *root, int k) {
        stack<Node*> st;
        Node* curr = root;
        int count = 0;

        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();
            count++;

            if (count == k) return curr->data;

            curr = curr->right;
        }

        return -1;
    }
};
