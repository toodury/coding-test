#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>

std::vector<int> solution(std::vector<std::string> operations) {
    std::deque<int> data_vec;

    for (int i = 0; i < operations.size(); i++)
    {
        std::string operation = operations[i];
        if (operation.substr(0, 1) == "I")
        {
            data_vec.push_back(stoi(operation.substr(2)));
        }
        else if (operation.substr(0, 1) == "D")
        {
            if (data_vec.size() == 0)
                continue;
            sort(data_vec.begin(), data_vec.end());
            if (operation.substr(2, 1) == "-")
            {
                data_vec.pop_front();
            }
            else
            {
                data_vec.pop_back();
            }
        }
    }
    sort(data_vec.begin(), data_vec.end());
    std::vector<int> answer;
    if (data_vec.size() == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(data_vec.back());
        answer.push_back(data_vec.front());
    }
    return answer;
}

void printVector(std::vector<int> solution)
{
    std::cout << "solution : ";
    for (int i = 0; i < solution.size(); i++)
    {
        std::cout << solution[i] << ", ";
    }
    std::cout << "\b\b " << std::endl;
}

int main() {

    std::vector<std::string> operations1 = {"I 16", "D 1"};
    std::vector<std::string> operations2 = { "I 7","I 5","I -5","D -1" };
    std::vector<int> solution1 = solution(operations1);
    std::vector<int> solution2 = solution(operations2);
	
    printVector(solution1);
    printVector(solution2);

	return 0;
}