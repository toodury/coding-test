#include <vector>
#include <algorithm>
#include <iostream>

int solution(std::vector<int> citations) {
    int answer = 0;
    int citationSize = citations.size();

    std::sort(citations.begin(), citations.end(), std::less<int>());

    for (int i = 0; i < citationSize; i++)
    {
        int currentCitation = citations[i];
        if (currentCitation <= citationSize - i)
        {
            if (answer < currentCitation)
                answer = currentCitation;
        }
        else
        {
            while (answer < currentCitation)
            {
                currentCitation--;
                if (currentCitation <= citationSize - i)
                    answer = currentCitation;
            }
            break;
        }
    }

    return answer;
}

int main()
{
    std::vector<int> citations = { 3, 0, 6, 1, 5 };

    int answer = solution(citations);

    std::cout << "answer : " << answer << std::endl;

    return 0;
}