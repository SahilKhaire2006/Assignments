#include <iostream>
#include <vector>
using namespace std;

class Graph_sak {
private:
    int vertices_sak;
    vector<vector<int>> adjList_sak;

public:
    Graph_sak(int v_sak) {
        vertices_sak = v_sak;
        adjList_sak.resize(vertices_sak);
    }

    void addEdge_sak(int src_sak, int dest_sak) {
        adjList_sak[src_sak].push_back(dest_sak);
        adjList_sak[dest_sak].push_back(src_sak);
    }

    void displayAdjList_sak() {
        cout << "\nAdjacency List:\n";
        for (int i_sak = 0; i_sak < vertices_sak; i_sak++) {
            cout << i_sak << " -> ";
            for (int neighbor_sak : adjList_sak[i_sak]) {
                cout << neighbor_sak << " ";
            }
            cout << endl;
        }
    }

    class MyQueue {
        int front, rear, size;
        vector<int> arr;
    public:
        MyQueue(int capacity) {
            arr.resize(capacity);
            front = rear = 0;
            size = capacity;
        }
        bool isEmpty() { return front == rear; }
        void enqueue(int val) {
            if (rear < size)
                arr[rear++] = val;
        }
        int dequeue() {
            if (!isEmpty())
                return arr[front++];
            return -1;
        }
    };

    class MyStack {
        int top;
        vector<int> arr;
    public:
        MyStack(int capacity) {
            arr.resize(capacity);
            top = -1;
        }
        bool isEmpty() { return top == -1; }
        void push(int val) {
            arr[++top] = val;
        }
        int pop() {
            if (!isEmpty())
                return arr[top--];
            return -1;
        }
    };

    void BFS_sak(int startVertex_sak) {
        vector<bool> visited_sak(vertices_sak, false);
        MyQueue queue_sak(vertices_sak);

        visited_sak[startVertex_sak] = true;
        queue_sak.enqueue(startVertex_sak);

        cout << "BFS Traversal: ";
        while (!queue_sak.isEmpty()) {
            int current_sak = queue_sak.dequeue();
            cout << current_sak << " ";

            for (int neighbor_sak : adjList_sak[current_sak]) {
                if (!visited_sak[neighbor_sak]) {
                    visited_sak[neighbor_sak] = true;
                    queue_sak.enqueue(neighbor_sak);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil_sak(int v_sak, vector<bool>& visited_sak) {
        visited_sak[v_sak] = true;
        cout << v_sak << " ";

        for (int neighbor_sak : adjList_sak[v_sak]) {
            if (!visited_sak[neighbor_sak]) {
                DFSUtil_sak(neighbor_sak, visited_sak);
            }
        }
    }

    void DFSRecursive_sak(int startVertex_sak) {
        vector<bool> visited_sak(vertices_sak, false);
        cout << "DFS Recursive Traversal: ";
        DFSUtil_sak(startVertex_sak, visited_sak);
        cout << endl;
    }

    void DFSIterative_sak(int startVertex_sak) {
        vector<bool> visited_sak(vertices_sak, false);
        MyStack stack_sak(vertices_sak);

        stack_sak.push(startVertex_sak);
        visited_sak[startVertex_sak] = true;

        cout << "DFS Iterative Traversal: ";
        while (!stack_sak.isEmpty()) {
            int current_sak = stack_sak.pop();
            cout << current_sak << " ";

            for (int neighbor_sak : adjList_sak[current_sak]) {
                if (!visited_sak[neighbor_sak]) {
                    visited_sak[neighbor_sak] = true;
                    stack_sak.push(neighbor_sak);
                }
            }
        }
        cout << endl;
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

    g_sak.displayAdjList_sak();

    int startVertex_sak;
    cout << "\nEnter starting vertex for traversals: ";
    cin >> startVertex_sak;

    g_sak.BFS_sak(startVertex_sak);
    g_sak.DFSRecursive_sak(startVertex_sak);
    g_sak.DFSIterative_sak(startVertex_sak);

    return 0;
}
