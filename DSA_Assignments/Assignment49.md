# Practical – Kruskal's Algorithm

**Name:** Sahil Ashok Khaire  
**Roll No.:** 13  
**Title:** Implementation of Kruskal's Algorithm to Find Minimum Spanning Tree using Adjacency List  

- Accept a weighted undirected graph from the user
- Represent the graph using adjacency list
- Implement Kruskal's algorithm to find Minimum Spanning Tree (MST)
- Use Union-Find data structure for cycle detection
- Display the edges and total weight of the MST

---

## Theory

A **Minimum Spanning Tree (MST)** is a subset of edges of a connected, weighted, undirected graph that connects all vertices together without any cycles and with the minimum possible total edge weight.

**Kruskal's Algorithm** is a greedy algorithm that finds a minimum spanning tree by sorting all edges by weight and adding them to the MST in ascending order, ensuring no cycles are formed. It uses the **Union-Find** (Disjoint Set Union) data structure for efficient cycle detection.

The algorithm works by:
1. Sorting all edges in non-decreasing order of their weight
2. Picking the smallest edge and checking if it forms a cycle with the spanning tree formed so far
3. If cycle is not formed, include this edge in the MST
4. Repeat until there are (V-1) edges in the MST

The **Adjacency List** representation is used for efficient storage of the graph, and edges are extracted from this representation for processing.

**Time Complexity**: O(E log E) for sorting + O(E α(V)) for Union-Find operations  
**Space Complexity**: O(V + E) for adjacency list and edge storage

Key terms: **MST**, **Kruskal's Algorithm**, **Union-Find**, **Disjoint Set**, **Greedy Algorithm**, **Cycle Detection**, **Adjacency List**

---

## Algorithm

### Algorithm: Create Adjacency List
1. Read the number of vertices `vertices_sak` and edges `edges_sak`
2. Create an array of lists `adjList_sak` of size `vertices_sak`
3. Each list element is a pair `(vertex, weight)`
4. For each weighted edge:
   - Read source `u_sak`, destination `v_sak`, and weight `weight_sak`
   - Add `(v_sak, weight_sak)` to `adjList_sak[u_sak]`
   - Add `(u_sak, weight_sak)` to `adjList_sak[v_sak]` (undirected graph)

### Algorithm: Extract Edges from Adjacency List
1. Create an edge list `edgesList_sak` to store all edges as `(weight, u, v)`
2. For each vertex `i_sak` from 0 to `vertices_sak-1`:
   - For each neighbor `(neighbor_sak, weight_sak)` in `adjList_sak[i_sak]`:
     - If `i_sak < neighbor_sak` (to avoid duplicates in undirected graph):
       - Add `(weight_sak, i_sak, neighbor_sak)` to `edgesList_sak`

### Algorithm: Union-Find Operations
1. **Find Operation**: 
   - Find the root of a vertex with path compression
   - Recursively find parent until root is found
2. **Union Operation**:
   - Union two sets by rank
   - Attach smaller rank tree under root of higher rank tree

### Algorithm: Kruskal's MST
1. Extract all edges from adjacency list to `edgesList_sak`
2. Sort `edgesList_sak` by weight in non-decreasing order
3. Initialize Union-Find structure with `vertices_sak` sets
4. Initialize MST edge count `mstCount_sak = 0` and total weight `totalWeight_sak = 0`
5. Create MST edge list `mstEdges_sak`
6. For each edge in sorted order:
   - If `mstCount_sak == vertices_sak - 1`, break
   - Extract `weight_sak`, `u_sak`, `v_sak` from current edge
   - If `u_sak` and `v_sak` are in different sets (no cycle):
     - Add edge to `mstEdges_sak`
     - Perform union of sets containing `u_sak` and `v_sak`
     - Add `weight_sak` to `totalWeight_sak`
     - Increment `mstCount_sak`
7. Display MST edges and total weight

---

## Program

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind_sak {
private:
    vector<int> parent_sak;
    vector<int> rank_sak;
    
public:
    UnionFind_sak(int n_sak) {
        parent_sak.resize(n_sak);
        rank_sak.resize(n_sak, 0);
        for (int i_sak = 0; i_sak < n_sak; i_sak++) {
            parent_sak[i_sak] = i_sak;
        }
    }
    
    int find_sak(int x_sak) {
        if (parent_sak[x_sak] != x_sak) {
            parent_sak[x_sak] = find_sak(parent_sak[x_sak]);
        }
        return parent_sak[x_sak];
    }
    
    void unionSets_sak(int x_sak, int y_sak) {
        int rootX_sak = find_sak(x_sak);
        int rootY_sak = find_sak(y_sak);
        
        if (rootX_sak != rootY_sak) {
            if (rank_sak[rootX_sak] < rank_sak[rootY_sak]) {
                parent_sak[rootX_sak] = rootY_sak;
            } else if (rank_sak[rootX_sak] > rank_sak[rootY_sak]) {
                parent_sak[rootY_sak] = rootX_sak;
            } else {
                parent_sak[rootY_sak] = rootX_sak;
                rank_sak[rootX_sak]++;
            }
        }
    }
};

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
    
    vector<tuple<int, int, int>> getEdgesList_sak() {
        vector<tuple<int, int, int>> edgesList_sak;
        
        for (int i_sak = 0; i_sak < vertices_sak; i_sak++) {
            for (auto& neighbor_sak : adjList_sak[i_sak]) {
                int v_sak = neighbor_sak.first;
                int weight_sak = neighbor_sak.second;
                if (i_sak < v_sak) {
                    edgesList_sak.push_back({weight_sak, i_sak, v_sak});
                }
            }
        }
        
        return edgesList_sak;
    }
    
    void kruskalMST_sak() {
        vector<tuple<int, int, int>> edgesList_sak = getEdgesList_sak();
        
        sort(edgesList_sak.begin(), edgesList_sak.end());
        
        UnionFind_sak uf_sak(vertices_sak);
        vector<tuple<int, int, int>> mstEdges_sak;
        int totalWeight_sak = 0;
        int mstCount_sak = 0;
        
        for (auto& edge_sak : edgesList_sak) {
            if (mstCount_sak == vertices_sak - 1) break;
            
            int weight_sak = get<0>(edge_sak);
            int u_sak = get<1>(edge_sak);
            int v_sak = get<2>(edge_sak);
            
            if (uf_sak.find_sak(u_sak) != uf_sak.find_sak(v_sak)) {
                uf_sak.unionSets_sak(u_sak, v_sak);
                mstEdges_sak.push_back(edge_sak);
                totalWeight_sak += weight_sak;
                mstCount_sak++;
            }
        }
        
        if (mstCount_sak != vertices_sak - 1) {
            cout << "MST not possible. Graph may be disconnected." << endl;
            return;
        }
        
        displayMST_sak(mstEdges_sak, totalWeight_sak);
    }
    
    void displayMST_sak(vector<tuple<int, int, int>>& mstEdges_sak, int totalWeight_sak) {
        cout << "\nMinimum Spanning Tree Edges:\n";
        for (auto& edge_sak : mstEdges_sak) {
            int weight_sak = get<0>(edge_sak);
            int u_sak = get<1>(edge_sak);
            int v_sak = get<2>(edge_sak);
            cout << u_sak << " - " << v_sak << " : " << weight_sak << endl;
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
    g_sak.kruskalMST_sak();
    
    return 0;
}
```

## Output
![alt text](Assignment49.png)