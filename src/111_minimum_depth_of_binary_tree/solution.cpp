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
    int level {1};
    void bfs(TreeNode *root) {
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int qSize = q.size();
            while (qSize--) {
                auto node = q.front();
                q.pop();
                if (node == nullptr) continue;
                if (node->left == nullptr && node->right == nullptr) return;
                q.push(node->left);
                q.push(node->right);
            }
            level++;
        }
    }
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        bfs(root);
        return level;
    }
};
