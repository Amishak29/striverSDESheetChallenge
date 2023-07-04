#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int colorfulGraph(int n, int m, int k, vector<int>& colors, vector<vector<int>>& edges) {
    vector<unordered_set<int>> adjList(n + 1);

    for (const auto& edge : edges) {
        int u = edge[0], v = edge[1];
        adjList[u].insert(v);
        adjList[v].insert(u);
    }

    int count = 0;

    for (int i = 1; i <= n; i++) {
        int color = colors[i];
        unordered_set<int> neighbors = adjList[i];

        bool hasSameColorNeighbor = false;
        for (int neighbor : neighbors) {
            if (colors[neighbor] == color) {
                hasSameColorNeighbor = true;
                break;
            }
        }

        if (!hasSameColorNeighbor) {
            count++;
        }
    }

    return count;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;

        vector<int> colors(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> colors[i];
        }

        vector<vector<int>> edges(M, vector<int>(2));
        for (int i = 0; i < M; i++) {
            cin >> edges[i][0] >> edges[i][1];
        }

        int result = colorfulGraph(N, M, K, colors, edges);
        cout << result << endl;
    }

    return 0;
}
