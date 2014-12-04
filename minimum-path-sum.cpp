class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        /* 难度：**
         * 动态规划问题，每一个节点与跟节点（左上角节点）的最短距离一定会经过左节点或右节点
         * 误区：此题不要转换为二叉树来计算根节点到叶子节点的最短距离，转换后增加时间复杂度
         * 如果给一个m*n的矩阵图，求左上角到右下的最短距离（路径不要求方向），此方法该如何求？
         */
        int m = grid.size();
        int n = grid.begin() -> size();
        //方法1：改变了grid节点值来存储最短距离
        for (int i = 1; i < n; ++i)
            grid[0][i] += grid[0][i-1];
        for (int i = 1; i < m; ++i)
        {
            grid[i][0] += grid[i-1][0];
            for (int j = 1; j < n; ++j)
            {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
        */
        //方法二：不改变grid值
        /*vector<int> hh;
        hh.resize(n);
        hh[0] = grid[0][0];
        for (int i = 1; i < n; ++i)
            hh[i] = hh[i-1] + grid[0][i];
        for (int i = 1; i < m; ++i)
        {
            hh[0] += grid[i][0];
            for (int j = 1; j < n; ++j)
                hh[j] = min(hh[j-1], hh[j]) + grid[i][j];
        }  
        return hh[n-1];
        */
    }
    
};
