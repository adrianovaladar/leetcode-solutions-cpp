/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "null";
        std::string answer;
        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();
            if (node == nullptr) answer += "null,";
            else {
                answer += std::to_string(node->val) + ",";
                queue.push(node->left);
                queue.push(node->right);
            }
        }
        return answer;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::stringstream ss(data);
        std::string val;
        std::getline(ss, val, ',');
        if (val == "null") return nullptr;
        TreeNode* answer = new TreeNode(stoi(val));
        queue<TreeNode*> queue;
        queue.push(answer);
        while (std::getline(ss, val, ',')) {
            TreeNode *node = queue.front();
            queue.pop();
            if (val != "null") {
                node->left = new TreeNode(stoi(val));
                queue.push(node->left);
            }
            std::getline(ss, val, ',');
            if (val != "null") {
                node->right = new TreeNode(stoi(val));
                queue.push(node->right);
            }
        }
        return answer;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
