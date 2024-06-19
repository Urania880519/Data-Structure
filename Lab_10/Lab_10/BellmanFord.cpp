#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int from;
    int to;
    int weight;
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};

vector<int> bellmanFord(int N, int S, const vector<Edge>& edges) {
    vector<int> dist(N + 1, INF);
    dist[S] = 0;


    for (int i = 1; i <= N - 1; ++i) {
        for (const auto& edge : edges) {
            if (dist[edge.from] != INF && dist[edge.to] > dist[edge.from] + edge.weight) {
                dist[edge.to] = dist[edge.from] + edge.weight;
            }
        }
    }


    for (const auto& edge : edges) {
        if (dist[edge.from] != INF && dist[edge.to] > dist[edge.from] + edge.weight) {
            vector<int> negative_cycle(N + 1, INF);
            return negative_cycle;
        }
    }

    return dist;
}


int main() {
    int N, M;
    cin >> N >> M;

    vector<Edge> edges;
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    int S, T;
    cin >> S >> T;

    vector<int> dist = bellmanFord(N, S, edges);
    int result = dist[T] == INF ? -1 : dist[T];
    cout << result << endl;

    return 0;
}