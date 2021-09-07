#include <iostream>
#include <vector>

std::vector<int> solution(int brown, int yellow) {

    int yellow_garo = 0, yellow_sero = 0;
    for (int i = 1; i <= sqrt(yellow); i++)
    {
        if (yellow % i == 0)
        {
            yellow_sero = i;
            yellow_garo = yellow / i;
        }
        if ((yellow_garo + 2) * (yellow_sero + 2) - yellow == brown)
            break;
    }

    std::vector<int> answer = { yellow_garo + 2, yellow_sero + 2 };

    return answer;
}

int main() {

    int brown = 24;
    int yellow = 24;

    std::vector<int> answer = solution(brown, yellow);

    std::cout << "answer : " << answer[0] << ", " << answer[1] << std::endl;



    return 0;
}