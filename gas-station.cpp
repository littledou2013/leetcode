class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        /* 难度：***
         * 使用空间复杂度O(1), 空间复杂度为O（n）来解决此题
         * N个节点组成一个环，节点编号为0,1,N-1，每个节点保存两个值，gas：能够走的距离，cost：到顺时针到下一个节点的距离，求是否存在一个节点顺时针方向走一圈，满足gas大于cost
         * 设置start作为起点，顺时针遍历节点，设置遍历到的节点为end,end初始值为start
         * 1、如果start到end之间的gas值之和大于等于start到end之间的cost值之后，则继续遍历下一个节点：++end
         * 2、否则以end之后的一个节点重新作为起点，start = end + 1, end = start;
         * 遍历结束条件：1、start >= size，说明已经尝试所有节点作为起点 2、start + size = end, 说明end已经回到了起点
         */
        int size = gas.size();
        for (int i = 1; i < size; ++i)
        {
            gas[i] += gas[i - 1];
            cost[i] += cost[i-1];
        }
        int gasAll = gas[size - 1];
        int costAll = cost[size - 1];
        if (gasAll < costAll)
            return -1;
        int end = 0, start = 0;
        while (start < size && end != start + size)
        {
            if ((gas[(end + size) % size] - gas[(start - 1 + size) % size] + gasAll) % gasAll >= (cost[(end + size) % size] - cost[(start - 1 + size) % size] + costAll) % costAll)
                ++end;
            else
            {
                start = end + 1;
                end = start;
            }
        }
        if (start < size)
            return start;
        else
            return -1;
    }
};
