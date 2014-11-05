/*
 * 题目大意： 寻找递增的旋转数组里面最小的数(存在重复元素）
 * 解题思路：折半查找。
 * 有序的旋转数组前半部分和后半部分都是递增的序列。数组第一个元素要大于等于最后一个元素。否则数组本身就是个递增的序列，第一个元素就是最小数
 * 如果不是递增序列，则取中间数。
 * 1.如果中间数大于数组的第一个元素（或者大于数组的最后一个元素），说明最小数存在后半段，范围缩小到中间数到最后一个元素左开右闭区间
 * 2.如果中间数小于数组的第一个元素（或者小于数组的最后一个元素），说明最小数存在前半段，范围缩小到第一个元素和中间数闭区间左开右闭区间。
 * 3.如果中间数等于数组第一个元素，需要特殊处理。
 * 3.1 如果中间数大于数组最后一个元素，说明最小数存在后半段， 范围缩小到中间数到最后一个元素左开右闭区间
 * 3.2 如果中间数等于数组最后一个元素，则需分别找出这第一个元素到中间数，和中间数到最后一个元素这两个区间的最小数，然后对这两个最小数进行比较，最后取最小值。
 */
 
 class Solution {
public:
    int findMin(vector<int> &num) {
        /*
        //使用直接顺序遍历，时间复杂度为O(n)，虽然简单，但是未利用到其有序的性质
        int minNum = num[0];
        int size = num.size();
        for (int i = 1; i < size; ++i)
        {
            if (minNum > num[i])
                minNum = num[i];
        }
        return minNum;
        */
        return getMin(num, 0, num.size() - 1);
    }
    int getMin(vector<int> &num, int low, int high)
    {
        if (low < high && num[low] >= num[high])
        {
            int mid = (low + high) / 2;
            if (num[mid] > num[high])
                return getMin(num, mid + 1, high);
            else if (num[mid] < num[high])
                return getMin(num, low + 1, mid);
            else //使用二分查找时注意情况的区分
                return min(getMin(num, low, mid), getMin(num, mid + 1, high));
        }
        else
            return num[low];
    }
};
