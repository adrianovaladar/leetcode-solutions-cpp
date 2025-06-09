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
    bool bfs(TreeNode *root) {
        if (root == nullptr) return true;
        std::queue<TreeNode *> q;
        q.push(root);
        int value = root->val;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int currentValue = node->val;
            if (currentValue != value) return false;
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }
        return true;
    }
public:
    bool isUnivalTree(TreeNode* root) {
        return bfs(root);
    }
};
