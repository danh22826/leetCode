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
    bool isSymmetric(TreeNode* root) {
        queue<pair<TreeNode*, TreeNode*>> qu;
        qu.push({root->right, root->left});
        while (!qu.empty()) {
            auto [a, b] = qu.front(); qu.pop();
            if (!a && !b) continue;
            if (!a || !b) return false;
            if (a->val != b->val) return false;
            qu.push({a->left, b->right});
            qu.push({a->right, b->left});
        }
        return true;
    }
};