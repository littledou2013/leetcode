class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<int> vec;
        int length = S.size();
        vector<vector<int> > solu;
        solu.push_back(vec);
        subset(S, vec, solu, length);
        return solu;
    }
    void subset(vector<int> &S, vector<int> &vec, vector<vector<int> >&solu, int length)
    {
        for (int i = length - 1; i >= 0; --i)
        {
            if (vec.empty() || (!vec.empty()&& S[i] > vec.back()))
            {
                 vec.push_back(S[i]);
                 solu.push_back(vec);
                 subset(S, vec, solu, length);
                 vec.pop_back();
            }
        }
    }
};
