#include <iostream>
#include <vector>
#include <queue>

int solution(std::vector<int> scoville, int K) {
    int answer = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq_scoville;

    for (int i = 0; i < scoville.size(); i++)
        pq_scoville.push(scoville[i]);

    while (true)
    {
        if (pq_scoville.top() >= K)
            break;
        if (pq_scoville.size() == 1)
            return -1;

        answer++;
        int taste1 = pq_scoville.top();
        pq_scoville.pop();
        int taste2 = pq_scoville.top();
        pq_scoville.pop();
        int newMenu = taste1 + 2 * taste2;
        pq_scoville.push(newMenu);
    }

    return answer;
}

int main() {

    std::vector<int> scoville = {1, 2, 3, 9, 10, 12};
    int K = 7;

    int solution1 = solution(scoville, K);

    std::cout << "solution1 : " << solution1 << std::endl;
	


    return 0;
	
}