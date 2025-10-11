//ZigZag Tree Traversal




/*
class Node {
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
    vector<int> zigZagTraversal(Node* root) {
        // code here
        stack<Node*> st1;
        stack<Node*> st2;
        
        int i = 1;
        
        vector<int> res;
        st1.push(root);
        int size =0;
        
        while(!st1.empty() || !st2.empty())
        {
            if(!st1.empty() && i%2!=0)
            {
                size = st1.size();
            }
            
            if(!st2.empty() && i%2==0)
            {
                size = st2.size();
            }
            
            while(size!=0 && i%2!=0)
            {
                Node *curr = st1.top();
                st1.pop();
                res.push_back(curr->data);
                if(curr->left)st2.push(curr->left);
                if(curr->right)st2.push(curr->right);
                size--;
            }
            
            while(size!=0 && i%2==0) 
            {
                Node *curr = st2.top();
                st2.pop();
                res.push_back(curr->data);
                if(curr->right)st1.push(curr->right);
                if(curr->left)st1.push(curr->left);
                size--;
            }
            i++;
        }
        return res;
    }
};
