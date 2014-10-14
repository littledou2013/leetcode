class Solution {
private:
    int A[128];
public:
    int lengthOfLongestSubstring(string s) {
        for (int i = 0; i < 128; ++i)
            A[i] = -1;
        /* 动态规划法：
         * 依次遍历，标记子串中出现的字符，遇到重复字符的时候，更新子串开始index
         */
        int size = s.size();
        int sIndex = 0, eIndex = 0;
        int maxLength = 0;
        for (int i = 0; i < size; ++i)
        {
            if (A[s[i]] != -1)
            {
                if (eIndex - sIndex > maxLength)
                    maxLength = eIndex - sIndex;
				for (int j = sIndex; j < A[s[i]]; ++j)
					A[s[j]] = -1;
                sIndex = A[s[i]] + 1; 
            }
            A[s[i]] = i;
            ++eIndex;
        }
        if (eIndex - sIndex > maxLength)
            maxLength = eIndex - sIndex;
        return maxLength;
    }
};
