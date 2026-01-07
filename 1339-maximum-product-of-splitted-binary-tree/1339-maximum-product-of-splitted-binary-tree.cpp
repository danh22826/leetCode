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
    long long totalSum = 0;
    long long maxProd = 0;

    int maxProduct(TreeNode* root) {
        totalSum = getSum(root);
        getSum(root);  
        return maxProd % 1000000007;
    }

    long long getSum(TreeNode* node) {
        if (!node) return 0;

        long long subSum = node->val + getSum(node->left) + getSum(node->right);

        if (totalSum > 0) {
            maxProd = max(maxProd, subSum * (totalSum - subSum));
        }

        return subSum;
    }
};