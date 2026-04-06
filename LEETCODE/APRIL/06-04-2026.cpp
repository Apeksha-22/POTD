//874. Walking Robot Simulation



class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dirIndex = 0;
        set<pair<int, int>> obstacleSet;
        for (const auto& obs : obstacles) {
            obstacleSet.insert({obs[0], obs[1]});
        }

        int x = 0, y = 0;
        int maxDistSquared = 0;

        for (int cmd : commands) {
            if (cmd == -2) {
                dirIndex = (dirIndex - 1 + 4) % 4;
            } else if (cmd == -1) {
                dirIndex = (dirIndex + 1) % 4;
            } else {
                for (int i = 0; i < cmd; ++i) {
                    int newX = x + directions[dirIndex].first;
                    int newY = y + directions[dirIndex].second;
                    if (obstacleSet.find({newX, newY}) != obstacleSet.end()) {
                        break;
                    }

                    x = newX;
                    y = newY;
                    maxDistSquared = max(maxDistSquared, x * x + y * y);
                }
            }
        }

        return maxDistSquared;
    }
};
