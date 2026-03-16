// K Sum Paths



/*
class Node {
  public:
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
    void Dfs(Node*root, int prefix, int k, unordered_map<int,int>&mp, int& cnt){
        if(!root) return;
        prefix += root->data;
        if(mp.count(prefix-k)) cnt += mp[prefix-k];
        
        mp[prefix]++;
        
        Dfs(root->left, prefix, k, mp, cnt);
        Dfs(root->right, prefix, k, mp, cnt);
        
        mp[prefix]--;
        
    }
    int countAllPaths(Node *root, int k) {
        // code here
        int cnt=0;
        unordered_map<int,int>mp;
        mp[0] = 1;
        Dfs(root, 0, k, mp, cnt);
        return cnt;
    }
};
