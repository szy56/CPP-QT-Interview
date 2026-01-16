/*
给你一个整数数组 nums 
其中元素已经按 升序 排列，请你将其转换为一棵 平衡 二叉搜索树。

平衡二叉树 是指该树所有节点的左右子树的高度相差不超过 1。

输入：nums = [-10,-3,0,5,9]
输出：[0,-3,9,-10,null,5]
解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：

*/

#include<iostream>
#include<vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//中序遍历，总是选择中间数字为根节点
TreeNode* helper(std::vector<int>& nums, int left, int right)
{
    if(left > right)
    {
        return nullptr;
    }

    int mid = (left + right) / 2;
    TreeNode* root = new TreeNode(nums[mid]);

    root->left = helper(nums, left, mid - 1);
    root->right = helper(nums, mid + 1, right);
    return root;
}

TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
}

//前序遍历方便输出
void printPreOrder(TreeNode *root)
{
    if(root == nullptr)
    {
        std::cout << "nullptr, ";
        return;
    }
    std::cout << root->val << ", ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main()
{
    std::vector<int> nums = {-10,-3,0,5,9};

    printPreOrder(sortedArrayToBST(nums));

    return 0;
}