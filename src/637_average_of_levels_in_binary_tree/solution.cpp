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
    vector<double> answer;
    vector<int> levelElements;
    vector<double> averageOfLevels(TreeNode* root, int level = 0) {
        if (root ==nullptr) return answer;
        if (level == answer.size()) {
            answer.emplace_back(root->val);
            levelElements.emplace_back(1);
        }
        else {
            answer.at(level) += root->val;
            levelElements.at(level)++;
        }
        averageOfLevels(root->left, level + 1);
        averageOfLevels(root->right, level + 1);
        if (level == 0) {
            for (int i {}; i < answer.size(); i++) {
                answer.at(i) = answer.at(i) / levelElements.at(i);
            }
        }
        return answer;
    }
};
