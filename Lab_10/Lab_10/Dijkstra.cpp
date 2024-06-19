#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

struct Node {
    int city;
    int cost;
    Node(int c, int co) : city(c), cost(co) {}
    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

int dijkstra(int N, const vector<vector<Edge>>& graph, int S, int T) {
    vector<int> dist(N + 1, INF);
    vector<bool> visited(N + 1, false);

    dist[S] = 0;

    for (int i = 0; i < N; ++i) {
        int minDist = INF, minNode = -1;

        
        for (int j = 1; j <= N; ++j) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                minNode = j;
            }
        }

        visited[minNode] = true;

        
        for (const auto& edge : graph[minNode]) {
            int v = edge.to;
            int w = edge.weight;

            if (!visited[v] && dist[minNode] != INF && dist[minNode] + w < dist[v]) {
                dist[v] = dist[minNode] + w;
            }
        }
    }

    return dist[T] == INF ? -1 : dist[T];
}



int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<Edge> > graph(N + 1);

    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(Edge(v, w));
        graph[v].push_back(Edge(u, w)); // Assuming it's an undirected graph, comment this line if directed.
    }

    int S, T;
    cin >> S >> T;

    int result = dijkstra(N, graph, S, T);
    cout << result << endl;

    return 0;
}