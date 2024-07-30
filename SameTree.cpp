#include <bits/stdc++.h>

using namespace std;

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
    vector<int> dfs(TreeNode* t) {
        vector<int> preorder;
        if (t == nullptr) {
            return preorder;
        }

        preorder.reserve(101);

        stack<TreeNode*> stack;
        stack.push(t);

        while (!stack.empty()) {
            TreeNode* ele = stack.top();
            stack.pop();
            if (ele == nullptr) {
                preorder.push_back(99999);
            } else {
                preorder.push_back(ele->val);
                stack.push(ele->right);
                stack.push(ele->left);
            }
        }

        return preorder;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (dfs(p) == dfs(q)) {
            return true;
        }
        return false;
    }
};