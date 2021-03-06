Day-2 Binary Tree Level Order Traversal II.cpp

/*

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]


*/



// Time:  O(n)
// Space: O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode *> que;

        if (root != nullptr) {
            que.emplace(root);
        }

        while (!que.empty()) {
            vector<int> level;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                auto *front = que.front();
                que.pop();
                level.emplace_back(front->val);
                if (front->left != nullptr) {
                    que.emplace(front->left);
                }
                if (front->right != nullptr) {
                    que.emplace(front->right);
                }
            }
            result.emplace_back(move(level));
        }
        
        // The only difference between binary-tree-level-order-traversal
        // and binary-tree-level-order-traversal-ii
        reverse(result.begin(), result.end());
        
        return result;
    }
};