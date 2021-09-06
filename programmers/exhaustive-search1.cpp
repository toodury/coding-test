#include <iostream>
#include <vector>

std::vector<int> solution(std::vector<int> answers) {
    int score1 = 0, score2 = 0, score3 = 0, max_score = 0;
    std::vector<int> max = { 1 };

    for (int i = 0; i < answers.size(); i++)
    {
        if ((i % 5) + 1 == answers[i])
            score1++;
        if (i % 2 == 0 && answers[i] == 2)
            score2++;
        else if (i % 8 == 1 && answers[i] == 1)
            score2++;
        else if (i % 8 == 3 && answers[i] == 3)
            score2++;
        else if (i % 8 == 5 && answers[i] == 4)
            score2++;
        else if (i % 8 == 7 && answers[i] == 5)
            score2++;
        if ((i % 10 == 0 || i % 10 == 1) && answers[i] == 3)
            score3++;
        else if ((i % 10 == 2 || i % 10 == 3) && answers[i] == 1)
            score3++;
        else if ((i % 10 == 4 || i % 10 == 5) && answers[i] == 2)
            score3++;
        else if ((i % 10 == 6 || i % 10 == 7) && answers[i] == 4)
            score3++;
        else if ((i % 10 == 8 || i % 10 == 9) && answers[i] == 5)
            score3++;
    }
    max_score = score1;
    if (score2 > score1)
    {
        max = { 2 };
        max_score = score2;
    }
    else if (score2 == max_score)
        max.push_back(2);
    if (score3 > max_score)
    {
        max = { 3 };
        max_score = score3;
    }
    else if (score3 == max_score)
        max.push_back(3);
    return max;
}

std::vector<int> solution2(std::vector<int> answers) {
    std::vector<int> max;
    std::vector<int> answer1 = { 1, 2, 3, 4, 5 };
    std::vector<int> answer2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    std::vector<int> answer3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    int score1 = 0, score2 = 0, score3 = 0, max_score;

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == answer1[i % 5])
            score1++;
        if (answers[i] == answer2[i % 8])
            score2++;
        if (answers[i] == answer3[i % 10])
            score3++;
    }

    max = { 1 };
    max_score = score1;
    if (score2 > max_score)
    {
        max = { 2 };
        max_score = score2;
    }
    else if (score2 == max_score)
        max.push_back(2);
    if (score3 > max_score)
    {
        max = { 3 };
        max_score = score3;
    }
    else if (score3 == max_score)
        max.push_back(3);

    return max;
}

template <typename T>
void printVector(std::vector<T> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << ", ";
    }
    std::cout << "\b\b " << std::endl;
}

int main() {

    std::vector<int> answers1 = { 1, 2, 3, 4, 5 };
    std::vector<int> answers2 = {1, 3, 2, 4, 2};

    std::vector<int> solution1 = solution(answers1);
    std::vector<int> solution2 = solution(answers2);

    printVector(solution1);
    printVector(solution2);



    return 0;
}