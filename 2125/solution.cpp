#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
private:
    int getAlerts(string row)
    {
        int num = 0;
        for (auto const s : row)
        {
            if (s == '1')
            {
                num++;
            }
        }
        return num;
    }

public:
    int numberOfBeams(vector<string> &bank)
    {
        int numBeam = 0;

        int up = 0, numUp = getAlerts(bank[0]);

        while (numUp == 0 && up < bank.size() - 1)
        {
            up++;
            numUp = getAlerts(bank[up]);
        }

        int dw = up + 1;

        while (dw < bank.size())
        {
            int numDw = getAlerts(bank[dw]);
            if (numDw == 0)
            {
                dw++;
                continue;
            }
            numBeam += numDw * numUp;
            up = dw;
            numUp = numDw;
            dw++;
        }
        return numBeam;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

// TEST_F(SolutionTest, test_001)
// {
//     vector<string> bank = {"011001", "000000", "010100", "001000"};
//     int num = solution.numberOfBeams(bank);
//     ASSERT_EQ(8, num);
// }

TEST_F(SolutionTest, test_002)
{
    vector<string> bank = {"0"};
    int num = solution.numberOfBeams(bank);
    ASSERT_EQ(0, num);
}
