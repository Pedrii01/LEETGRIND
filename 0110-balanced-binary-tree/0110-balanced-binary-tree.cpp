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
    int LDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int ld = max(LDepth(root->left), LDepth(root->right)) + 1;
        return ld;
    }

    int RDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int rd = max(RDepth(root->left), RDepth(root->right)) + 1;
        return rd;
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        int l = LDepth(root->left);
        int r = RDepth(root->right);

        if (abs(l - r) <= 1 &&
            isBalanced(root->left) &&
            isBalanced(root->right)) {
            return true;
        }

        return false;
    }
};