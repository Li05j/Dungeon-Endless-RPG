#include <string>
#include <vector>

#define mfor(s, r) for (int i = s; i < r; i++)

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        std::string common = "";
        int vlen = strs.size();
        if (vlen == 1)
            return strs[0];
        if (vlen == 2)
            return lcp(strs[0], strs[1]);

        common = lcp(strs[0], strs[1]);
        mfor(2, vlen)
        {
            common = lcp(common, strs[i]);
        }
        return common;
    }

    std::string lcp(std::string s1, std::string s2)
    {
        std::string ret = "";
        mfor(0, min(s1.length(), s2.length()))
        {
            if (s1[i] == s2[i])
            {
                ret.push_back(s1[i]);
            }
            else
            {
                break;
            }
        };
        return ret;
    }

    int min(int a, int b)
    {
        return a < b ? a : b;
    }
};