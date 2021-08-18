#include <iostream>
#include <vector>
#include <unordered_map>

std::string solution(std::vector<std::string> participant, std::vector<std::string> completion) {

    std::unordered_map<std::string, int> completion_table;

    for (int i = 0; i < completion.size(); i++)
    {
        if (completion_table.find(completion[i]) != completion_table.end())
            completion_table[completion[i]]++;
        completion_table.insert(std::make_pair(completion[i], 1));
    }

    for (int i = 0; i < participant.size(); i++)
    {
        if (!completion_table[participant[i]])
            return participant[i];
        completion_table[participant[i]]--;
        if (completion_table[participant[i]] == 0)
            completion_table.erase(participant[i]);
    }
}

int main() {

    std::vector<std::string> participant1 = { "leo", "kiki", "eden" };
    std::vector<std::string> participant2 = { "marina", "josipa", "nikola", "vinko", "filipa" };
    std::vector<std::string> participant3 = { "mislav", "stanko", "mislav", "ana" };
    std::vector<std::string> completion1 = { "eden", "kiki" };
    std::vector<std::string> completion2 = { "josipa", "filipa", "marina", "nikola" };
    std::vector<std::string> completion3 = { "stanko", "ana", "mislav" };

    std::string solution1 = solution(participant1, completion1);
    std::string solution2 = solution(participant2, completion2);
    std::string solution3 = solution(participant3, completion3);

    std::cout << "solution1 : " << solution1 << std::endl
        << "solution2 : " << solution2 << std::endl
        << "solution3 : " << solution3 << std::endl;



	return 0;
}