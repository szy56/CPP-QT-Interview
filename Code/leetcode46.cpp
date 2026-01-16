/*
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

 

示例 1：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
示例 2：

输入：nums = [0,1]
输出：[[0,1],[1,0]]
示例 3：

输入：nums = [1]
输出：[[1]]

*/

#include<iostream>
#include<vector>
using namespace std;

void backTrack(vector<vector<int>> &res, vector<int> &vec, const vector<int> &nums, vector<bool> &used)
{
    if(vec.size() == nums.size())
    {
        res.push_back(vec);
    }
    else
    {
        for(int i = 0; i < nums.size(); ++i)
        {
            if(used[i])continue;
            used[i] = true;
            vec.push_back(nums[i]);
            backTrack(res,vec,nums,used);
            vec.pop_back();
            used[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int>vec;
    vector<bool>used(nums.size(), false);
    backTrack(res, vec, nums, used);
    return res;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> res = permute(nums);

    for(int i = 0; i < res.size(); ++i)
    {
        for(int j = 0; j < res[i].size(); ++j)
        {
            cout << res[i][j] << ',';
        }
        cout << endl;
    }

    return 0;
}