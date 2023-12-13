#include <iostream>
#include <queue>
#include <vector>

class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);// 添加v到w的边
    void BFS(int start);

private:
    int vertices;
    std::vector<std::vector<int>> adjacencyList;// 邻接表
};

Graph::Graph(int vertices) : vertices(vertices), adjacencyList(vertices) {}

void Graph::addEdge(int v, int w) {
    adjacencyList[v].push_back(w);
}

void Graph::BFS(int start) {
    std::vector<bool> visited(vertices, false);     // 记录是否访问过
    std::queue<int> queue;   // 用于BFS的队列

    visited[start] = true;
    queue.push(start);

    while (!queue.empty()) {
        int currentVertex = queue.front();
        std::cout << currentVertex << " ";
        queue.pop();

        for (int adjacentVertex : adjacencyList[currentVertex]) {
            if (!visited[adjacentVertex]) {
                visited[adjacentVertex] = true;
                queue.push(adjacentVertex);
            }
        }
    }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "BFS starting from vertex 2: ";
    g.BFS(2);

    return 0;
}
