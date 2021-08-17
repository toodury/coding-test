#include <iostream>
#include <vector>

std::vector<int> solution(std::vector<int> prices) {
    std::vector<int> answer;

    for (int i = 0; i < prices.size(); i++)
    {
        int cnt = 1;
        for (int j = i + 1; j < prices.size(); j++)
        {
            if (prices[i] > prices[j])
            {
                answer.push_back(cnt);
                break;
            }
            else
            {
                if (j == prices.size() - 1)
                    answer.push_back(cnt);
                cnt++;
            }
        }
    }
    answer.push_back(0);

    return answer;
}

int main() {

    std::vector<int> prices = {1, 2, 3, 2, 3};

    std::vector<int> solution1 = solution(prices);

    std::cout << "solution : [";
    for (int i = 0; i < solution1.size(); i++)
    {
        std::cout << solution1[i] << ", ";
    }
    std::cout << "\b\b]" << std::endl;




    return 0;
}