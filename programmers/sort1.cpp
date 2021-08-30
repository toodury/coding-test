#include <iostream>
#include <vector>

std::vector<int> solution(std::vector<int> array, std::vector<std::vector<int>> commands) {
    std::vector<int> answer;

    for (int i = 0; i < commands.size(); i++)
    {
        std::vector<int> command = commands[i];
        std::vector<int> cutted;
        for (size_t j = command[0] - 1; j < command[1]; j++)
        {
            cutted.push_back(array[j]);
        }
        for (size_t j = 0; j < cutted.size(); j++)
        {
            for (size_t k = j + 1; k < cutted.size(); k++)
            {
                if (cutted[j] > cutted[k])
                {
                    int tmp = cutted[j];
                    cutted[j] = cutted[k];
                    cutted[k] = tmp;
                }
            }
        }
        answer.push_back(cutted[command[2] - 1]);
    }

    return answer;
}

template<typename T>
void printVector(std::vector<T> vec)
{
    std::cout << "solution : ";
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << ", ";
    std::cout << "\b\b " << std::endl;
}

int main() {

    std::vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
    std::vector<std::vector<int>> commands = { {2, 5, 3}, {4, 4, 1}, { 1, 7, 3 } };
    std::vector<int> solution1 = solution(array, commands);
    printVector(solution1);

	return 0;
}