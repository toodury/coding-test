#include <iostream>
#include <vector>

std::vector<int> solution(std::vector<int> progresses, std::vector<int> speeds)
{
    std::vector<int> answer;
    std::vector<bool> finished;
    int lastDistributedIndex = -1;

    for (int i = 0; i < progresses.size(); i++)
    {
        finished.push_back(false);
    }

    while (1)
    {
        for (int i = 0; i < progresses.size(); i++)
        {
            if (progresses[i] < 100)
                progresses[i] += speeds[i];
            else
                finished[i] = true;
        }

        bool tmp = true;
        for (int i = lastDistributedIndex + 1; i < finished.size(); i++)
        {
            tmp = tmp && finished[i];
            if (!tmp)
            {
                if (lastDistributedIndex + 1 < i)
                    answer.push_back(i - lastDistributedIndex - 1);
                lastDistributedIndex = i - 1;
                break;
            }
            else if (i + 1 == finished.size())
                answer.push_back(i - lastDistributedIndex);
        }

        bool isFinished = true;

        for (int i = 0; i < finished.size(); i++)
        {
            isFinished = isFinished && finished[i];
        }
        if (isFinished)
            break;
    }

    return answer;
}
void print_vector(std::vector<int> intVector, std::string vectorName)
{
	std::cout << vectorName << " : ";
	for (int i = 0; i < intVector.size(); i++)
	{
		std::cout << intVector[i];
		if (i == intVector.size() - 1)
			break;
		std::cout << ", ";
	}
	std::cout << std::endl;
}

int main() {

	std::vector<int> progresses = {93, 30, 55};
	std::vector<int> progresses2 = { 95, 90, 99, 99, 80, 99 };
	std::vector<int> speeds = {1, 30, 5};
	std::vector<int> speeds2 = {1, 1, 1, 1, 1, 1};
	//std::vector<int> answer = {2, 1};
	//std::vector<int> answer2 = {1, 3, 2};

	std::vector<int> answer = solution(progresses, speeds);
	std::vector<int> answer2 = solution(progresses2, speeds2);

    print_vector(answer, "answer");
    print_vector(answer2, "answer2");
    
	

	return 0;
}