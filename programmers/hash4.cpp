#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::vector<int> solution(std::vector<std::string> genres, std::vector<int> plays) {
    std::vector<int> answer;
    std::unordered_map<std::string, int> genrePlayTotal;
    std::unordered_map<std::string, int>::iterator it;
    std::unordered_map<std::string, std::vector<std::vector<int>>> genreIndexPlay;

    for (int i = 0; i < genres.size(); i++)
    {
        if (genrePlayTotal.find(genres[i]) == genrePlayTotal.end())
        {
            genrePlayTotal.insert({ genres[i], plays[i] });
            genreIndexPlay.insert({ genres[i], {{i, plays[i]}} });
        }
        else
        {
            genrePlayTotal[genres[i]] += plays[i];
            genreIndexPlay[genres[i]].push_back({ i, plays[i] });
        }
    }

    while (!genrePlayTotal.empty())
    {
        int max_play = 0;
        std::string max_genre;
        for (it = genrePlayTotal.begin(); it != genrePlayTotal.end(); it++)
        {
            if (max_play < it->second)
            {
                max_genre = it->first;
                max_play = it->second;
            }
        }

        int max_index = 0, second_max_index = 0, second_max_play = 0;
        max_play = 0;
        if (genreIndexPlay[max_genre].size() == 1)
            answer.push_back(genreIndexPlay[max_genre][0][0]);
        else
        {
            for (int i = 0; i < genreIndexPlay[max_genre].size(); i++)
            {
                if (genreIndexPlay[max_genre][i][1] > max_play)
                {
                    second_max_play = max_play;
                    second_max_index = max_index;
                    max_play = genreIndexPlay[max_genre][i][1];
                    max_index = genreIndexPlay[max_genre][i][0];
                }
                else if (genreIndexPlay[max_genre][i][1] > second_max_play)
                {
                    second_max_play = genreIndexPlay[max_genre][i][1];
                    second_max_index = genreIndexPlay[max_genre][i][0];
                }
            }
            answer.push_back(max_index);
            answer.push_back(second_max_index);
        }
        genrePlayTotal.erase(max_genre);
    }
    return answer;
}

template <typename T>
void printVector(std::vector<T> vec)
{
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << ", ";
    std::cout << "\b\b " << std::endl;
}

int main() {

    std::vector<std::string> genres = { "classic", "pop", "classic", "classic", "pop" };
    std::vector<int> plays = { 500, 600, 150, 800, 2500 };
    std::vector<int> answer = solution(genres, plays);

    printVector(answer);



    return 0;
}