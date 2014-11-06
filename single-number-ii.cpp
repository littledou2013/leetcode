class Solution {
public:
    int singleNumber(int A[], int n) {
        /* 
         * 此方法可以解决所有数组中除了一个数其他数出现k次的数组， 一般对于一个数出现奇数次，其他出现偶数次的数组使用直接异或的方式比较简单，
         */
        /*int num[32] = {0};
        int res = 0;
        for (int i = 0; i < 32; ++i)
        {
            for (int j = 0; j < n; ++j)
                num[i] += (A[j] >> i) & 1;
            res |= (num[i] % 3) << i;
        }
        return res;
        */
        /* 针对此题更快速的方法
         *  这是一个更快一些的解法，利用三个变量分别保存各个二进制位上 1 出现一次、两次、三次的分布情况，最后只需返回变量一就行了。代码如下：
         * 解释：每次循环先计算 twos，即出现两次的 1 的分布，然后计算出现一次的 1 的分布，接着 二者进行与操作得到出现三次的 1 的分布情况，然后对 threes 取反，再与 ones、twos进行与操作，这样的目的是将出现了三次的位置清零。
        这个方法虽然更快、更省空间了，但是并不通用。
         * 个人认为此方法难于理解，并且不易想清楚其中逻辑思维
         */
         
         int one=0, two=0, three=0;  
        for(int i=0; i<n; i++){  
            two |= one&A[i];  
            one^=A[i];  
            //cout<<one<<endl;  
            three=one&two;  
            one&= ~three;  
            two&= ~three;  
        }  
        return one;  
    }
};
