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
    int getMaximumDiameter(TreeNode *root, int &result) {
        if (root == nullptr) return 0;
        int left {};
        int right {};
        left = getMaximumDiameter(root->left, result);
        right = getMaximumDiameter(root->right, result);
        result = std::max(result,left + right);
        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int answer {};
        int result {};
        getMaximumDiameter(root, result);
        return result;
    }
};
