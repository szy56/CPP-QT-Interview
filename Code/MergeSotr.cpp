/*
归并排序  时间复杂度：O(nlogn) 空间：O(n) 稳定
*/

#include<iostream>
#include<vector>

std::vector<int> merge(std::vector<int> &nums1, std::vector<int> &nums2)
{
    //合并两个有序数组，使用临时数组实现
    std::vector<int> temp;
    int i = 0, j = 0;
    while(i < nums1.size() && j < nums2.size())
    {
        if(nums1[i] < nums2[j])
        {
            temp.push_back(nums1[i++]);
        }
        else
        {
            temp.push_back(nums2[j++]);
        }
    }

    while(i < nums1.size())
    {
        temp.push_back(nums1[i++]);
    }

    while(j < nums2.size())
    {
        temp.push_back(nums2[j++]);
    }

    return temp;
}

std::vector<int> mergeSort(std::vector<int>& nums)
{
    if(nums.size() <= 1)
    {
        return nums;
    }

    int mid = nums.size() / 2;
    std::vector<int> left, right;
    left.assign(nums.begin(), nums.begin() + mid);
    right.assign(nums.begin() + mid, nums.end());
    left = mergeSort(left);
    right = mergeSort(right);

    //合并数组，并返回
    return merge(left, right);
}

int main()
{
    std::vector<int> nums = {8, 4, 5, 7, 1, 3, 6, 2};
    std::vector<int> res = mergeSort(nums);

    for(int i = 0; i < res.size(); ++i)
    {
        std::cout << res[i] << ", ";
    }

    return 0;
}