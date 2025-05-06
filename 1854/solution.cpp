#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"
#include <queue>
#include <gtest/gtest.h>

using namespace std;

class SeatManager
{
public:
    SeatManager(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            available_seats.push(i);
        }
    }

    int reserve()
    {
        int result = available_seats.top();
        available_seats.pop();
        return result;
    }

    void unreserve(int seatNumber)
    {
        available_seats.push(seatNumber);
    }

private:
    priority_queue<int> available_seats;
};

class SolutionTest : public testing::Test
{
protected:
    // SeatManager manager;
};

TEST_F(SolutionTest, test_001)
{
    int n = 5;
    SeatManager manager(n);
    int output1 = manager.reserve();
    ASSERT_EQ(1, output1);
    int output2 = manager.reserve();
    ASSERT_EQ(2, output2);
    manager.unreserve(2);
    int output3 = manager.reserve();
    ASSERT_EQ(2, output3);
    int output4 = manager.reserve();
    ASSERT_EQ(3, output4);
    int output5 = manager.reserve();
    ASSERT_EQ(4, output5);
    int output6 = manager.reserve();
    ASSERT_EQ(5, output6);
    manager.unreserve();
}
