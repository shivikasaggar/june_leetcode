/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
int lefth(TreeNode*root){
    if(root==NULL){
        return 0;
    }
    else{
        return 1+lefth(root->left);
    }
}
int righth(TreeNode*root){
    if(root==NULL){
        return 0;
    }
    else{
        return 1+righth(root->right);
    }
}

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        // return(1+countNodes(root->left)+countNodes(root->right));
        
        int lh=lefth(root);
        int rh=righth(root);
        if(lh==rh){
            return (1<<lh)-1;
        }
        else{
            return 1+countNodes(root->left)+countNodes(root->right);
        }
    }
};
