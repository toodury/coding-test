#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include <iostream>

bool findElement(std::vector<int> vec, int target)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == target)
            return true;
    }
    return false;
}

int solution(int n, std::vector<std::vector<int>> edge) {
    int answer = 0;
    std::vector<std::vector<int>>::iterator it;

    std::deque<int> forTraverse = { 1 };
    std::vector<int> traversed = { 1 };
    std::unordered_map<int, int> depth_map;
    depth_map.insert({1, 0});

    while (true)
    {
        int node = forTraverse.front();
        forTraverse.pop_front();
        for (it = edge.begin(); it != edge.end(); it++)
        {
            if ((*it)[0] == node)
            {
                if (!findElement(traversed, (*it)[1]))
                {
                    traversed.push_back((*it)[1]);
                    forTraverse.push_back((*it)[1]);
                    int new_depth = depth_map[(*it)[0]] + 1;
                    depth_map.insert({(*it)[1], new_depth});
                    answer++;
                }
            }
            if ((*it)[1] == node)
            {
                if (!findElement(traversed, (*it)[0]))
                {
                    traversed.push_back((*it)[0]);
                    forTraverse.push_back((*it)[0]);
                    int new_depth = depth_map[(*it)[1]] + 1;
                    depth_map.insert({ (*it)[0], new_depth });
                    answer++;
                }
            }
        }

        if (forTraverse.empty())
            break;
    }

    int max_depth = 0;
    std::unordered_map<int, int>::iterator itr;
    for (itr = depth_map.begin(); itr != depth_map.end(); itr++)
    {
        if (itr->second > max_depth)
        {
            max_depth = itr->second;
            answer = 1;
        }
        else if (itr->second == max_depth)
            answer++;
    }

    return answer;
}

int main() {

    int n = 6;
    int n2 = 6;
    std::vector<std::vector<int>> edge = { {3, 6},{4, 3},{3, 2},{1, 3},{1, 2},{2, 4},{5, 2} };
    std::vector<std::vector<int>> edge2 = { {1, 2}, {2, 3} };

    int answer = solution(n, edge);
    int answer2 = solution(n2, edge2);

    std::cout << "answer : " << answer << std::endl;
    std::cout << "answer2 : " << answer2 << std::endl;


    return 0;
}