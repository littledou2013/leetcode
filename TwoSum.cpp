/* 此题需注意时间复杂度在nlogn
 * 方法一:排序方式
 * 标记其开始位置时，排序
 */
class Solution {
    struct Number
    {
        int value;
        int index;
        bool operator < (const Number &num) const
        {
            return value < num.value;
        }
    };
    vector<Number> num;
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        size_t size = numbers.size();
        num.resize(size);
        for (int i = 0; i < size; ++i)
        {
            num[i].index = i + 1;
            num[i].value = numbers[i];
        }
        sort(num.begin(), num.end());
        int i = 0, j = size - 1;
        while (i < j)
        {
            if (num[i].value + num[j].value > target)
                --j;
            else if (num[i].value + num[j].value < target)
                ++i;
            else
                break;
        }
        vector<int> result;
        if (num[i].index < num[j].index)
        {  
            result.push_back(num[i].index);
            result.push_back(num[j].index);
        }
        else
         {  
            result.push_back(num[j].index);
            result.push_back(num[i].index);
        }
        return result;
    }
};
/* 方法二：使用map
 * 使用map记录已经扫描过的值，及其位置
 */
class Solution {
    map<int, int> mp;
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        size_t size = numbers.size();
        int index1, index2;
        for (int i = 0; i < size; ++i)
        {
            if (mp.find(target - numbers[i]) != mp.end())
            {
                index1 = mp[target - numbers[i]];
                index2 = i + 1;
                break;
            }
            else
            {
                mp.insert(make_pair(numbers[i], i + 1));
            }
        }
        vector<int> result;
        result.push_back(index1);
        result.push_back(index2);
        return result;
    }
};
