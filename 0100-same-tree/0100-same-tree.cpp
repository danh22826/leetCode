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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*,TreeNode*>> qu;
        qu.push({p,q});
        while(!qu.empty())
        {
            auto [a,b] = qu.front(); qu.pop();
            if(!a && !b) continue;
            if(!a || !b) return false;
            if(a->val != b->val) return false;
            qu.push({a->left,b->left});
            qu.push({a->right,b->right}); 
        }
        return true;
    }
};