#include <iostream>
#include <vector>

int solution(std::vector<int> priorities, int location) {

    int answer = 0;

    while (true)
    {
        int printNext = priorities[0];
        bool isPrinted = true;

        for (int i = 1; i < priorities.size(); i++)
        {
            if (printNext < priorities[i])
                isPrinted = false;
        }

        if (isPrinted)
        {
            answer++;
            if (location == 0)
                return answer;
            for (int i = 0; i < priorities.size() - 1; i++)
            {
                priorities[i] = priorities[i + 1];
            }
            priorities.pop_back();
            location--;
        }
        else
        {
            for (int i = 0; i < priorities.size() - 1; i++)
            {
                priorities[i] = priorities[i + 1];
            }
            priorities.pop_back();
            priorities.push_back(printNext);
            if (location == 0)
                location = priorities.size() - 1;
            else
                location--;
        }
    }
}

int main() {

    std::vector<int> priorities1 = { 2, 1, 3, 2 };
    std::vector<int> priorities2 = { 1, 1, 9, 1, 1, 1 };
    int location1 = 2;
    int location2 = 0;

    int solution1 = solution(priorities1, location1);
    int solution2 = solution(priorities2, location2);

    std::cout << "solution1 : " << solution1 << std::endl << "solution2 : " << solution2;

	return 0;
}