#include <vector>

bool findElem(std::vector<int> vec, int target)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == target)
            return true;
    }
    return false;
}

void dfs(std::vector<std::vector<int>> graph, std::vector<int>& traversedNodes, int node, int size)
{
    if (!findElem(traversedNodes, node))
        traversedNodes.push_back(node);
    for (int i = 0; i < size; i++)
    {
        if (graph[node][i] == 1 && !findElem(traversedNodes, i))
        {
            dfs(graph, traversedNodes, i, size);
        }
    }
}

int solution(int n, std::vector<std::vector<int>> computers) {
    int answer = 0;

    std::vector<int> traversedNodes;
    int node = 0;

    while (traversedNodes.size() < n)
    {
        int nodesTraversed = traversedNodes.size();
        dfs(computers, traversedNodes, node, n);
        node++;
        if (traversedNodes.size() > nodesTraversed)
            answer++;
    }
    return answer;
}

int main()
{
    int n1 = 3;
    int n2 = 3;
    std::vector<std::vector<int>> computers1 = { {1, 1, 0},{1, 1, 0},{0, 0, 1} };
    std::vector<std::vector<int>> computers2 = { {1, 1, 0},{1, 1, 1},{0, 1, 1} };
    int answer1 = solution(n1, computers1);
    int answer2 = solution(n2, computers2);



    return 0;
}