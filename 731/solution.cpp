#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;
class MyCalendarTwo
{
    vector<vector<int>> non_overlapping;
    vector<vector<int>> overlapping;

public:
    MyCalendarTwo()
    {
    }

    bool book(int startTime, int endTime)
    {
        for (const auto &event : this->overlapping)
        {
            if (max(event[0], startTime) < min(event[1], endTime))
            {
                return false; // Overlap detected
            }
        }

        for (const auto &event : this->non_overlapping)
        {
            if (max(event[0], startTime) < min(event[1], endTime))
            {
                // If there's an overlap with a non-overlapping event,
                // we need to add it to the overlapping events.
                this->overlapping.push_back({max(event[0], startTime), min(event[1], endTime)});
            }
        }
        this->non_overlapping.push_back({startTime, endTime});
        return true; // No overlap detected, we can book the event
    }
};

class SolutionTest : public testing::Test
{
protected:
    MyCalendarTwo calendar;
};

TEST_F(SolutionTest, test_001)
{
    string word1 = "";
    string word2 = "";
    MyCalendarTwo calendar;
    bool result = calendar.book(10, 20);
    ASSERT_TRUE(result);
    result = calendar.book(50, 60);
    ASSERT_TRUE(result);
    result = calendar.book(10, 40);
    ASSERT_TRUE(result);
    result = calendar.book(5, 15);
    ASSERT_FALSE(result);
    result = calendar.book(5, 10);
    ASSERT_TRUE(result);
    result = calendar.book(25, 55);
    ASSERT_TRUE(result);
}
