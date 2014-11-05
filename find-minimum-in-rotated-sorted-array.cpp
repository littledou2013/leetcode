/*
 * 题目大意： 寻找递增的旋转数组里面最小的数(不存在重复元素）
 * 解题思路：折半查找。
 * 有序的旋转数组前半部分和后半部分都是递增的序列。数组第一个元素要大于最后一个元素。否则数组本身就是个递增的序列，第一个元素就是最小数
 * 如果不是递增序列，则取中间数。
 * 1.中间元素大于最后一个元素（或大于第一个元素）， 说明最小数存在后半段，范围缩小到中间数到最后一个元素左开右闭区间
 * 2.如果中间数小于数组的第一个元素（或者小于数组的最后一个元素），说明最小数存在前半段，范围缩小到第一个元素和中间数闭区间左开右闭区间。
 */
 
class Solution {
public:
    int findMin(vector<int> &num) {
        /*
            二分查找
         */
        int low = 0, high = num.size() - 1, mid;
        while (low < high && num[low] > num[high])
        {
            mid = (low + high) / 2;
            if (num[mid] > num[high])
                low = mid + 1;
            else
            {
                ++low;
                high = mid;
            }
        }
        return num[low];
    }
};
