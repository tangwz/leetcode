/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> in_degree(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            in_degree[prerequisites[i][0]]++;
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> q;
        vector<bool> visited(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) q.push(i);
        }

        while (!q.empty())
        {
            int course = q.front();
            q.pop();
            visited[course] = true;
            for (int i = 0; i < graph[course].size(); i++) {
                if ((--in_degree[graph[course][i]]) == 0) q.push(graph[course][i]);
            }
        }

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) return false;
        }
        return true;
    }
};

