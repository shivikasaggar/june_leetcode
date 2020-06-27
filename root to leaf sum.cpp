//Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
//An example is the root-to-leaf path 1->2->3 which represents the number 123.
//Find the total sum of all root-to-leaf numbers.
//Note: A leaf is a node with no children.
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
int helper(TreeNode*root,int ans){
    if(root==NULL){
        return 0;
    }
    ans=(ans*10)+root->val;
    if(root->left==NULL&&root->right==NULL){
        return ans;
    }
    return(helper(root->left,ans)+helper(root->right,ans));
}
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root ==NULL){
            return 0;
        }
        return helper(root,0);
    }
};
