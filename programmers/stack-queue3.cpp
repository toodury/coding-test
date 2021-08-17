#include <iostream>
#include <vector>
#include <deque>

int solution(int bridge_length, int weight, std::vector<int> truck_weights) {

    int answer = 0;
    std::deque<int> trucks;
    std::deque<int> trucksPassing;
    std::deque<int> trucksTimeLeft;
    for (int i = 0; i < truck_weights.size(); i++)
        trucks.push_back(truck_weights[i]);


    while (true)
    {
        if (trucks.size() == 0 && trucksPassing.size() == 0)
            return answer;

        if (trucksTimeLeft.size() > 0)
        {
            for (int i = 0; i < trucksTimeLeft.size(); i++)
            {
                trucksTimeLeft[i]--;
            }
            if (trucksTimeLeft[0] == 0)
            {
                trucksTimeLeft.pop_front();
                trucksPassing.pop_front();
            }
        }

        int currentWeight = 0;
        for (int i = 0; i < trucksPassing.size(); i++)
            currentWeight += trucksPassing[i];
        if (trucks.size() > 0)
        {
            if (currentWeight + trucks[0] > weight)
            {
                answer++;
                continue;
            }
            trucksPassing.push_back(trucks[0]);
            trucks.pop_front();
            trucksTimeLeft.push_back(bridge_length);
        }
        answer++;
    }
}

int main() {

    int bridge_length1 = 2;
    int weight1 = 10;
    std::vector<int> truck_weights1 = { 7, 4, 5, 6 };
    int bridge_length2 = 100;
    int weight2 = 100;
    std::vector<int> truck_weights2 = { 10 };
    int bridge_length3 = 100;
    int weight3 = 100;
    std::vector<int> truck_weights3 = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };

    int solution1 = solution(bridge_length1, weight1, truck_weights1);
    int solution2 = solution(bridge_length2, weight2, truck_weights2);
    int solution3 = solution(bridge_length3, weight3, truck_weights3);

    std::cout << "solution1 : " << solution1 << std::endl
        << "solution2 : " << solution2 << std::endl
        << "solution3 : " << solution3 << std::endl;
	return 0;
}