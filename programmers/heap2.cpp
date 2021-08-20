#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

struct compare {
    bool operator()(std::vector<int> v1, std::vector<int> v2) {
        if (v1[1] > v2[1])
            return true;
        return false;
    }
};

int solution(std::vector<std::vector<int>> jobs) {
    int time = 0;
    int answer = 0;

    std::unordered_map<int, bool> jobs_map;

    for (int i = 0; i < jobs.size(); i++)
    {
        jobs[i].push_back(i);
        jobs_map.insert(std::make_pair(i, false));
    }

    for (int i = 0; i < jobs.size(); i++)
    {
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, compare> shortest_job_first;
        for (int j = 0; j < jobs.size(); j++)
        {
            if (jobs[j][0] <= time && !jobs_map[j])
                shortest_job_first.push(jobs[j]);
        }
        if (shortest_job_first.size() == 0)
        {
            time += 1;
            i--;
            continue;
        }
        time += shortest_job_first.top()[1];
        answer += time - shortest_job_first.top()[0];
        jobs_map[shortest_job_first.top()[2]] = true;
    }
    return answer / jobs.size();
}
bool compare2(std::vector<int> v1, std::vector<int> v2) {
    if (v1[1] < v2[1])
        return true;
    return false;
}
int solutionTwo(std::vector<std::vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    int size = jobs.size();
    sort(jobs.begin(), jobs.end(), compare2);
    while (jobs.size() >= 1)
    {
        for (int i = 0; i < jobs.size(); i++)
        {
            if (jobs[i][0] <= time)
            {
                time += jobs[i][1];
                answer += time - jobs[i][0];
                jobs.erase(jobs.begin() + i);
                break;
            }
            if (i == jobs.size() - 1)
                time++;
        }
    }

    answer /= size;
    return answer;
}

int main() {

    std::vector<std::vector<int>> jobs = { {0, 3}, {1, 9}, {2, 6} };

    int solution1 = solution(jobs);
    int solution2 = solutionTwo(jobs);

    std::cout << "solution1 : " << solution1 << std::endl;
    std::cout << "solution2 : " << solution2 << std::endl;

    
	

	return 0;
}