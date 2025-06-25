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
    void dfs(TreeNode* root, double target, int &answer) {
        double currentDifference = abs(root->val - target);
        if (currentDifference < abs(target - answer)) answer = root->val;
        else if (currentDifference == abs(target - answer)) answer = std::min(root->val, answer);
        if (root->left) dfs(root->left, target, answer);
        if (root->right) dfs(root->right, target, answer);
    }
public:
    int closestValue(TreeNode* root, double target) {
        int answer = root->val;
        dfs(root, target, answer);
        return answer;
    }
};
