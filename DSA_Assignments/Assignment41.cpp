#include <iostream>
#include <queue>
using namespace std;

class Graph_sak {
private:
    int vertices_sak;
    int** adjMatrix_sak;
    
public:
    Graph_sak(int v_sak) {
        vertices_sak = v_sak;
        adjMatrix_sak = new int*[vertices_sak];
        for (int i_sak = 0; i_sak < vertices_sak; i_sak++) {
            adjMatrix_sak[i_sak] = new int[vertices_sak];
            for (int j_sak = 0; j_sak < vertices_sak; j_sak++) {
                adjMatrix_sak[i_sak][j_sak] = 0;
            }
        }
    }
    
    void addEdge_sak(int src_sak, int dest_sak) {
        adjMatrix_sak[src_sak][dest_sak] = 1;
        adjMatrix_sak[dest_sak][src_sak] = 1;
    }
    
    void displayMatrix_sak() {
        cout << "\nAdjacency Matrix:\n";
        for (int i_sak = 0; i_sak < vertices_sak; i_sak++) {
            for (int j_sak = 0; j_sak < vertices_sak; j_sak++) {
                cout << adjMatrix_sak[i_sak][j_sak] << " ";
            }
            cout << endl;
        }
    }
    
    void BFS_sak(int startVertex_sak) {
        bool* visited_sak = new bool[vertices_sak];
        for (int i_sak = 0; i_sak < vertices_sak; i_sak++) {
            visited_sak[i_sak] = false;
        }
        
        queue<int> queue_sak;
        visited_sak[startVertex_sak] = true;
        queue_sak.push(startVertex_sak);
        
        cout << "BFS Traversal: ";
        while (!queue_sak.empty()) {
            int current_sak = queue_sak.front();
            cout << current_sak << " ";
            queue_sak.pop();
            
            for (int i_sak = 0; i_sak < vertices_sak; i_sak++) {
                if (adjMatrix_sak[current_sak][i_sak] == 1 && !visited_sak[i_sak]) {
                    visited_sak[i_sak] = true;
                    queue_sak.push(i_sak);
                }
            }
        }
        cout << endl;
        delete[] visited_sak;
    }
    
    void DFSUtil_sak(int v_sak, bool visited_sak[]) {
        visited_sak[v_sak] = true;
        cout << v_sak << " ";
        
        for (int i_sak = 0; i_sak < vertices_sak; i_sak++) {
            if (adjMatrix_sak[v_sak][i_sak] == 1 && !visited_sak[i_sak]) {
                DFSUtil_sak(i_sak, visited_sak);
            }
        }
    }
    
    void DFS_sak(int startVertex_sak) {
        bool* visited_sak = new bool[vertices_sak];
        for (int i_sak = 0; i_sak < vertices_sak; i_sak++) {
            visited_sak[i_sak] = false;
        }
        
        cout << "DFS Traversal: ";
        DFSUtil_sak(startVertex_sak, visited_sak);
        cout << endl;
        delete[] visited_sak;
    }
    
    ~Graph_sak() {
        for (int i_sak = 0; i_sak < vertices_sak; i_sak++) {
            delete[] adjMatrix_sak[i_sak];
        }
        delete[] adjMatrix_sak;
    }
};

int main() {
    int vertices_sak, edges_sak;
    
    cout << "Enter number of vertices: ";
    cin >> vertices_sak;
    
    cout << "Enter number of edges: ";
    cin >> edges_sak;
    
    Graph_sak g_sak(vertices_sak);
    
    cout << "Enter edges (source destination):\n";
    for (int i_sak = 0; i_sak < edges_sak; i_sak++) {
        int src_sak, dest_sak;
        cin >> src_sak >> dest_sak;
        g_sak.addEdge_sak(src_sak, dest_sak);
    }
    
    g_sak.displayMatrix_sak();
    g_sak.BFS_sak(0);
    g_sak.DFS_sak(0);
    
    return 0;
}