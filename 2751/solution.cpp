#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

struct Robot {
    int position;
    int health;
    char direction;
    int index;  // original index
};

vector<Robot> getSortedRobots(vector<int>& positions, vector<int>& healths, string& directions) {
    int n = positions.size();
    vector<Robot> robots(n);
    for (int i = 0; i < n; i++) {
        robots[i] = {positions[i], healths[i], directions[i], i};
    }
    sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
        return a.position < b.position;
    });
    return robots;
}

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<Robot> robots = getSortedRobots(positions, healths, directions);
        vector<Robot> stack;

        for (Robot& robot : robots) {
            if (robot.direction == 'R') {
                stack.push_back(robot);
            } else {
                while (robot.health > 0 && !stack.empty() && stack.back().direction == 'R') {
                    Robot& current = stack.back();
                    if (robot.health > current.health) {
                        robot.health--;
                        stack.pop_back();
                        // Continue while loop to check next R in stack
                    } else if (robot.health == current.health) {
                        stack.pop_back();
                        robot.health = 0;
                    } else { // robot.health < current.health
                        current.health--;
                        robot.health = 0; // L dies
                        break;
                    }
                }
                if (robot.health > 0) {
                    stack.push_back(robot);
                }
            }
        }

        sort(stack.begin(), stack.end(), [](const Robot &a, const Robot& b) {
            return a.index < b.index;
        });

        vector<int> result;
        for (const Robot & robot: stack) {
            result.push_back(robot.health);
        }

        return result;
    }
};

TEST(SolutionTest, test_001)
{
    Solution solution;
    vector<int> positions = {1, 2};
    vector<int> healths = {3, 4};
    string directions = "RL";
    vector<int> result = solution.survivedRobotsHealths(positions, healths, directions);
    (void)result;
    SUCCEED();
}
