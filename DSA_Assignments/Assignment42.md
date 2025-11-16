# Practical – Prim's Algorithm

**Name:** Sahil Ashok Khaire  
**Roll No.:** 13  
**Title:** Implementation of Prim's Algorithm to Find Minimum Spanning Tree  

- Accept a weighted undirected graph from the user
- Represent the graph using adjacency list
- Implement Prim's algorithm to find Minimum Spanning Tree (MST)
- Display the edges and total weight of the MST

---

## Theory

A **Minimum Spanning Tree (MST)** is a subset of edges of a connected, weighted, undirected graph that connects all vertices together without any cycles and with the minimum possible total edge weight.

**Prim's Algorithm** is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph. It starts with an arbitrary vertex and grows the MST one vertex at a time by always adding the cheapest possible connection from the tree to another vertex.

The algorithm uses a **priority queue** (min-heap) to efficiently select the next edge with the minimum weight. The **Adjacency List** representation is used for efficient storage and traversal of the graph, especially for sparse graphs.

Key terms: **MST**, **Prim's Algorithm**, **Priority Queue**, **Greedy Algorithm**, **Adjacency List**

---

## Algorithm

### Algorithm: Create Adjacency List
1. Read the number of vertices `vertices_sak` and edges `edges_sak`
2. Create an array of lists `adjList_sak` of size `vertices_sak`
3. For each weighted edge:
   - Read source `u_sak`, destination `v_sak`, and weight `weight_sak`
   - Add `(v_sak, weight_sak)` to `adjList_sak[u_sak]`
   - Add `(u_sak, weight_sak)` to `adjList_sak[v_sak]` (undirected graph)

### Algorithm: Prim's MST
1. Create a min-heap `pq_sak` to store (weight, vertex, parent)
2. Create arrays:
   - `key_sak` to store minimum weight to connect each vertex
   - `inMST_sak` to track if vertex is in MST
   - `parent_sak` to store parent of each vertex in MST
3. Initialize `key_sak[0] = 0` and push `(0, 0, -1)` to `pq_sak`
4. While `pq_sak` is not empty:
   - Extract minimum weight vertex `u_sak` from `pq_sak`
   - If `u_sak` is not in MST:
     - Mark `u_sak` in MST
     - If `parent_sak[u_sak] != -1`, add edge to MST
     - For each adjacent vertex `v_sak` of `u_sak`:
       - If `v_sak` not in MST and edge weight < `key_sak[v_sak]`:
         - Update `key_sak[v_sak]` and `parent_sak[v_sak]`
         - Push `(key_sak[v_sak], v_sak, u_sak)` to `pq_sak`
5. Display MST edges and total weight

---

## Program

```cpp
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

    int findMinKey_sak(vector<int>& key_sak, vector<bool>& inMST_sak) {
        int min_sak = INT_MAX, minIndex_sak = -1;
        for (int v_sak = 0; v_sak < vertices_sak; v_sak++) {
            if (!inMST_sak[v_sak] && key_sak[v_sak] < min_sak) {
                min_sak = key_sak[v_sak];
                minIndex_sak = v_sak;
            }
        }
        return minIndex_sak;
    }

    void primMST_sak() {
        vector<int> key_sak(vertices_sak, INT_MAX);
        vector<int> parent_sak(vertices_sak, -1);
        vector<bool> inMST_sak(vertices_sak, false);

        key_sak[0] = 0;  // Start from vertex 0
        int totalWeight_sak = 0;

        for (int count = 0; count < vertices_sak - 1; count++) {
            int u_sak = findMinKey_sak(key_sak, inMST_sak);
            inMST_sak[u_sak] = true;
            totalWeight_sak += key_sak[u_sak];

            for (auto& neighbor_sak : adjList_sak[u_sak]) {
                int v_sak = neighbor_sak.first;
                int weight_sak = neighbor_sak.second;

                if (!inMST_sak[v_sak] && weight_sak < key_sak[v_sak]) {
                    parent_sak[v_sak] = u_sak;
                    key_sak[v_sak] = weight_sak;
                }
            }
        }

        cout << "\nMinimum Spanning Tree Edges:\n";
        for (int i_sak = 1; i_sak < vertices_sak; i_sak++) {
            cout << parent_sak[i_sak] << " - " << i_sak << " : " << key_sak[i_sak] << endl;
        }
        cout << "Total Weight of MST: " << totalWeight_sak << endl;
    }

    void displayGraph_sak() {
        cout << "\nAdjacency List:\n";
        for (int i_sak = 0; i_sak < vertices_sak; i_sak++) {
            cout << i_sak << " -> ";
            for (auto& neighbor_sak : adjList_sak[i_sak]) {
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
```

## Output
![alt text](Assignment42.png)