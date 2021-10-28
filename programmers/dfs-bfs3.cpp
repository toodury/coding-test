#include <string>
#include <vector>
#include <deque>
#include <unordered_map>

template<typename T>
bool findElem(std::vector<T> vec, T target)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (target == vec[i])
            return true;
    }
    return false;
}

bool isConnected(std::string str1, std::string str2, int wordSize)
{
    int diffCnt = 0;
    for (int i = 0; i < wordSize; i++)
    {
        if (str1[i] != str2[i])
            diffCnt++;
    }
    if (diffCnt == 1)
        return true;
    else
        return false;
}

int bfs(std::vector<std::vector<int>> graph, int startNode, std::string target, std::vector<std::string> words)
{
    std::vector<int> traversedNodes;
    int nodeCnt = graph[0].size();
    std::deque<int> waitingNodes;
    int node = startNode;
    std::unordered_map<int, int> nodeDepth;
    nodeDepth.insert({ node, 0 });

    while (traversedNodes.size() < nodeCnt)
    {
        if (words[node] == target)
            return nodeDepth[node];

        for (int i = 0; i < graph[node].size(); i++)
        {
            if (graph[node][i] == 1 && !findElem(traversedNodes, i))
            {
                waitingNodes.push_back(i);
                nodeDepth.insert({ i, nodeDepth[node] + 1 });
            }
        }

        if (waitingNodes.size() == 0)
            return 0;

        node = waitingNodes[0];
        waitingNodes.pop_front();
    }

}

int solution(std::string begin, std::string target, std::vector<std::string> words) {

    if (!findElem(words, target))
        return 0;

    int wordSize = target.size();

    // make graph
    std::vector<std::vector<int>> graph;

    for (int i = 0; i <= words.size(); i++)
    {
        graph.push_back({});

        for (int j = 0; j < words.size(); j++)
        {
            if (i == words.size())
            {
                if (isConnected(begin, words[j], wordSize))
                    graph[i].push_back(1);
                else
                    graph[i].push_back(0);
            }
            else
            {
                if (isConnected(words[i], words[j], wordSize))
                    graph[i].push_back(1);
                else
                    graph[i].push_back(0);
            }
        }
    }

    int answer = bfs(graph, graph.size() - 1, target, words);

    return answer;
}

int main()
{
    std::string begin1 = "hit";
    std::string begin2 = "hit";
    std::string begin3 = "hit";

    std::string target1 = "cog";
    std::string target2 = "cog";
    std::string target3 = "cog";

    std::vector<std::string> words1 = { "hot", "dot", "dog", "lot", "log", "cog" };
    std::vector<std::string> words2 = { "hot", "dot", "dog", "lot", "log" };
    std::vector<std::string> words3 = { "hot", "dot", "lot", "log", "cog" };

    int answer1 = solution(begin1, target1, words1);
    int answer2 = solution(begin2, target2, words2);
    int answer3 = solution(begin3, target3, words3);


    return 0;
}