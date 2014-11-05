class Solution {
private:
    struct Sub
    {
        int product;
        int abso;
    };
public:
    int maxProduct(int A[], int n) {
    /*
     * 首先最朴素的方法超时，使用两个数组分别来记录从0到i元素之间乘积的最大值，以及绝对值最大的乘积值，此题比较难，特别是如何通过一次遍历来求得结果， 此题如果要求子序列怎么求？
     */
        vector<Sub> vec;
        vec.resize(n);
        bool hasN = false;
        int ptr;  //记录从非0开始的子数组中第一个负数的位置
        vec[0].product = A[0];
        vec[0].abso = A[0];
        if (A[0] < 0) 
        {
            hasN = true;
            ptr = 0;
        }
        for (int i = 1; i < n; ++i)
        {
            /* A[i]分为三种情况大于0小于0等于0
             * 如果等于0则vec[i].start = i, vec[i].end = i, vec[i].product = 0, vec[i].abso = 0;
             * 如果大于0 if (vec[i-1].product <= 0) vec[i].product = A[i]; else vec[i].prodcut = A[i] * vec[i-1].product;
             * 如果小于0 if (vec[i-1].abso < 0) vec[i] = vec[i-1].abso * vec[i] 如果vec[i-1].abso > 0，
             */
            vec[i].abso = vec[i-1].abso == 0 ? A[i]: vec[i-1].abso * A[i]; //记录连续的非0子序列的乘积
            if (A[i] == 0)
            {
                hasN = false;
                vec[i].product = 0;
            }
            else if (A[i] > 0)
            {
               
                if (vec[i - 1].product <= 0)
                    vec[i].product = A[i];
                else
                    vec[i].product = vec[i-1].product * A[i];
            }
            else
            {
                if (vec[i-1].product == 0)
                {
                    vec[i].product = A[i];
                    hasN = true;
                    ptr = i;
                }
                else if (vec[i-1].product > 0)
                {
                    if (vec[i - 1].abso < 0)
                        vec[i].product = vec[i].abso; //证明前面有奇数个负数，在乘上一个负数，就等于此子序列的乘积
                    else
                    {
                        if (hasN) //先判断是否有负数， 有负数则把第一个负数之前的子序列的乘积除掉
                        {
                            vec[i].product = vec[i-1].abso * A[i] / vec[ptr].abso;
                        }
                        else
                        {
                            vec[i].product = A[i];
                            hasN = true;
                            ptr = i;
                        }
                    }
                }
                else
                    vec[i].product = vec[i].abso;
            }
        }
        int result  = A[0];
        for (int i = 0; i < n; ++i)
        {
            if (vec[i].product > result)
                result = vec[i].product;
        }
        
        return result;
        
    }
};
