class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> taskCount;
        taskCount.resize(26);
        for (const auto &task : tasks) {
            taskCount[task - 'A']++;
        }
        std::priority_queue<int> tasksQueue;
        for (const auto &count : taskCount) {
            if (count > 0) tasksQueue.push(count);
        }
        std::queue<std::pair<int,int>> tasksAndTimeQueue;
        int time {};
        while (!tasksQueue.empty() || !tasksAndTimeQueue.empty()) {
            time++;
            if (!tasksQueue.empty()) {
                if (tasksQueue.top() - 1 > 0) tasksAndTimeQueue.push({tasksQueue.top() - 1, time + n});
                tasksQueue.pop();
            }
            else time = tasksAndTimeQueue.front().second;
            if (!tasksAndTimeQueue.empty() && tasksAndTimeQueue.front().second == time) {
                tasksQueue.push(tasksAndTimeQueue.front().first);
                tasksAndTimeQueue.pop();
            }
        }
        return time;
    }
};
