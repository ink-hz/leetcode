/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */

// @lc code=start
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }

        return buildMaxBinaryTree(nums, 0, nums.size()-1);
    }

    TreeNode* buildMaxBinaryTree(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        // 当前节点 找出当前数组中的最大数，并把左边的数据和右边的数据丢进循环继续遍历
        int index = -1;
        int max = INT_MIN;
        for (int i = start; i <= end; ++i) {
            if (nums[i] > max) {
                index = i;
                max = nums[i];
            }
        }

        TreeNode* cur = new TreeNode();
        cur->val = max;

        cur->left = buildMaxBinaryTree(nums, start, index-1);
        cur->right = buildMaxBinaryTree(nums, index+1, end);

        return cur;
    }
};
// @lc code=end

