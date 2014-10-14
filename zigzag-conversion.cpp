class Solution {
public:
    string convert(string s, int nRows) {
    /* 找出指形规律
     */ string str = s;
        int k = 0, size = str.size();
        for (int i = 0; i < nRows; ++i)
        {
            if (i == 0 || i == nRows - 1)
            {
                int j = i; 
                while (j < size)
                {
                    str[k++] = s[j];
                    j += nRows > 1 ? 2 * nRows - 2 : 1;
                }
            }
            else
            {
                //“之”字形，先往下在往上
                int j = i;
                while (j < size)
                {
                    str[k++] = s[j];
                    j += (nRows - i - 1)*2;
                    if (j < size)
                    {
                        str[k++] = s[j];
                        j += i * 2;
                    }
                }
            }
        }
        return str;
    }
};
