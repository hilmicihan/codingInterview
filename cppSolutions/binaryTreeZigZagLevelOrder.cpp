
/*
103. Binary Tree Zigzag Level Order Traversal
Medium

4770

154

Add to List

Share
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
link : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
*/
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
#include <string>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    void dfs(TreeNode *root, vector<vector<int>> &result, int level)
    {
        if (!root)
            return;
        if (level > result.size())
            result.push_back({});
        result[level - 1].push_back(root->val);

        dfs(root->left, result, level + 1);

        dfs(root->right, result, level + 1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        int level = 1;
        vector<vector<int>> result;
        dfs(root, result, level);
        for (int i = 1; i < result.size(); i += 2)
        {
            std::reverse(result[i].begin(), result[i].end());
        }
        return result;
    }
};