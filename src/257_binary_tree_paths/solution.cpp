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
    std::vector<std::string> answer;
    void backtracking(TreeNode *root, std::string currentPath) {
        if (root == nullptr) return;
        if (!currentPath.empty()) currentPath += "->";
        currentPath += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            answer.emplace_back(currentPath);
            return;
        }
        backtracking(root->left, currentPath);
        backtracking(root->right, currentPath);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        std::string currentPath;
        backtracking(root, currentPath);
        return answer;        
    }
};
