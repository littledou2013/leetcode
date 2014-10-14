class Solution {
public:
    int reverse(int x) {
        bool positive = true;
        if (x < 0)
        {
            positive = false;
            x = -x;
        }
        int sum = 0;
        while (x > 0)
        {
            sum *= 10;
            sum += x % 10;
            x /= 10;
        }
        if (positive)
            return sum;
        else
            return -sum;
    }
};
