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
    vector<int>v;
    int sumNumbers(TreeNode* root) {
        int sum=0,ans=0;
        if(!root) return 0;
        tree(root,sum);
        for(auto i:v) ans+=i;
        return ans;
    }
    void tree(TreeNode* root,int sum){
        sum=sum*10+root->val;
        if(!root->left && !root->right){ 
            v.push_back(sum); 
            return;
            }
        if(root->left) tree(root->left,sum);
        if(root->right) tree(root->right,sum);
    }
};
