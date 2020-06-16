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
class Solution {
public:
    TreeNode* temp;
    TreeNode* searchBST(TreeNode* root, int val) {
    search(root,val);
    if(temp==NULL) 
        return NULL;
    return temp;
    }
    void search(TreeNode* root, int val){
        if (root == NULL) 
            return;
        if(val==root->val) 
            temp=root;
        search(root->left,val);
        search(root->right,val);
    }
    
};
