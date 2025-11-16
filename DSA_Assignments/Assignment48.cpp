#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph_sak {
private:
    int vertices_sak;
    vector<vector<pair<int, int>>> adjList_sak;

public:
    Graph_sak(int v_sak) {
        vertices_sak = v_sak;
        adjList_sak.resize(vertices_sak);
    }

    void addEdge_sak(int u_sak, int v_sak, int weight_sak) {
        adjList_sak[u_sak].push_back({v_sak, weight_sak});
        adjList_sak[v_sak].push_back({u_sak, weight_sak});
    }

    void primMST_sak() {
        vector<int> key_sak(vertices_sak, INT_MAX);
        vector<bool> inMST_sak(vertices_sak, false);
        vector<int> parent_sak(vertices_sak, -1);

        key_sak[0] = 0;

        for (int count_sak = 0; count_sak < vertices_sak - 1; count_sak++) {
            int u_sak = -1;
            int minKey_sak = INT_MAX;

            // Find vertex with minimum key value not in MST
            for (int v_sak = 0; v_sak < vertices_sak; v_sak++) {
                if (!inMST_sak[v_sak] && key_sak[v_sak] < minKey_sak) {
                    minKey_sak = key_sak[v_sak];
                    u_sak = v_sak;
                }
            }

            if (u_sak == -1)
                break;

            inMST_sak[u_sak] = true;

            for (auto neighbor_sak : adjList_sak[u_sak]) {
                int v_sak = neighbor_sak.first;
                int weight_sak = neighbor_sak.second;

                if (!inMST_sak[v_sak] && weight_sak < key_sak[v_sak]) {
                    key_sak[v_sak] = weight_sak;
                    parent_sak[v_sak] = u_sak;
                }
            }
        }

        displayMST_sak(parent_sak, key_sak);
    }

    void displayMST_sak(vector<int>& parent_sak, vector<int>& key_sak) {
        int totalWeight_sak = 0;
        cout << "\nMinimum Spanning Tree Edges:\n";
        for (int i_sak = 1; i_sak < vertices_sak; i_sak++) {
            cout << parent_sak[i_sak] << " - " << i_sak << " : " << key_sak[i_sak] << endl;
            totalWeight_sak += key_sak[i_sak];
        }
        cout << "Total Weight of MST: " << totalWeight_sak << endl;
    }

    void displayGraph_sak() {
        cout << "\nAdjacency List:\n";
        for (int i_sak = 0; i_sak < vertices_sak; i_sak++) {
            cout << i_sak << " -> ";
            for (auto neighbor_sak : adjList_sak[i_sak]) {
                cout << "(" << neighbor_sak.first << ", " << neighbor_sak.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices_sak, edges_sak;

    cout << "Enter number of vertices: ";
    cin >> vertices_sak;

    cout << "Enter number of edges: ";
    cin >> edges_sak;

    Graph_sak g_sak(vertices_sak);

    cout << "Enter edges (source destination weight):\n";
    for (int i_sak = 0; i_sak < edges_sak; i_sak++) {
        int u_sak, v_sak, weight_sak;
        cin >> u_sak >> v_sak >> weight_sak;
        g_sak.addEdge_sak(u_sak, v_sak, weight_sak);
    }

    g_sak.displayGraph_sak();
    g_sak.primMST_sak();

    return 0;
}