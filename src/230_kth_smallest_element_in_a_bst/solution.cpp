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
    std::vector<int> vec;
    void getValues (TreeNode* root) {
        if (root == nullptr) return;
        vec.emplace_back(root->val);
        if (root->left != nullptr) getValues(root->left);
        if (root->right != nullptr) getValues(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        getValues(root);
        std::sort(vec.begin(),vec.end());
        return vec.at(k-1);
    }
};
