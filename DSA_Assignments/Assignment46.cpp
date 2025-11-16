#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include<tuple>
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
    vector<vector<int>> adjMatrix_sak;
    
public:
    Graph_sak(int v_sak) {
        vertices_sak = v_sak;
        adjMatrix_sak.resize(vertices_sak, vector<int>(vertices_sak, 0));
    }
    
    void addEdge_sak(int u_sak, int v_sak, int weight_sak) {
        adjMatrix_sak[u_sak][v_sak] = weight_sak;
        adjMatrix_sak[v_sak][u_sak] = weight_sak;
    }
    
    vector<tuple<int, int, int>> getEdgesList_sak() {
        vector<tuple<int, int, int>> edgesList_sak;
        
        for (int i_sak = 0; i_sak < vertices_sak; i_sak++) {
            for (int j_sak = i_sak + 1; j_sak < vertices_sak; j_sak++) {
                if (adjMatrix_sak[i_sak][j_sak] != 0) {
                    edgesList_sak.push_back({adjMatrix_sak[i_sak][j_sak], i_sak, j_sak});
                }
            }
        }
        
        return edgesList_sak;
    }
    
    void kruskalMST_sak() {
        vector<tuple<int, int, int>> edgesList_sak = getEdgesList_sak();
        
        sort(edgesList_sak.begin(), edgesList_sak.end());
        
        UnionFind_sak uf_sak(vertices_sak);
        vector<tuple<int, int, int>> mst_sak;
        int totalWeight_sak = 0;
        int mstCount_sak = 0;
        
        for (auto& edge_sak : edgesList_sak) {
            int weight_sak = get<0>(edge_sak);
            int u_sak = get<1>(edge_sak);
            int v_sak = get<2>(edge_sak);
            
            if (uf_sak.find_sak(u_sak) != uf_sak.find_sak(v_sak)) {
                uf_sak.unionSets_sak(u_sak, v_sak);
                mst_sak.push_back({u_sak, v_sak, weight_sak});
                totalWeight_sak += weight_sak;
                mstCount_sak++;
                
                if (mstCount_sak == vertices_sak - 1) {
                    break;
                }
            }
        }
        
        if (mstCount_sak != vertices_sak - 1) {
            cout << "MST not possible. Graph may be disconnected." << endl;
            return;
        }
        
        cout << "\nMinimum Spanning Tree Edges:\n";
        for (auto& edge_sak : mst_sak) {
            cout << get<0>(edge_sak) << " - " << get<1>(edge_sak) << " : " << get<2>(edge_sak) << endl;
        }
        cout << "Total Weight of MST: " << totalWeight_sak << endl;
    }
    
    void displayMatrix_sak() {
        cout << "\nAdjacency Matrix:\n";
        cout << "   ";
        for (int i_sak = 0; i_sak < vertices_sak; i_sak++) {
            cout << i_sak << " ";
        }
        cout << endl;
        
        for (int i_sak = 0; i_sak < vertices_sak; i_sak++) {
            cout << i_sak << "  ";
            for (int j_sak = 0; j_sak < vertices_sak; j_sak++) {
                cout << adjMatrix_sak[i_sak][j_sak] << " ";
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
    
    g_sak.displayMatrix_sak();
    g_sak.kruskalMST_sak();
    
    return 0;
}