//https://leetcode.com/problems/add-one-row-to-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
     void AddNode(TreeNode* &tree, int v, int d, int k){
        if (k+1!=d) {if (tree->left!=nullptr) AddNode(tree->left,v,d,k+1);
                     if (tree->right!=nullptr) AddNode(tree->right,v,d,k+1); }
        else {
            TreeNode* l = new TreeNode(v);
            TreeNode* r = new TreeNode(v);
            if (tree->left!=nullptr) l->left=tree->left;
            if (tree->right!=nullptr) r->right=tree->right;
            tree->left = l;
            tree->right = r;
        }
    }

    
TreeNode* addOneRow(TreeNode* root, int v, int d) {
if (d==1) {
    TreeNode* newtr = new TreeNode(v);
    newtr->left=root;
    return newtr;
}
else {
    AddNode(root,v,d,1);
    return root;
}
    }
};
