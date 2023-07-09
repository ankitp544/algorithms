/**
BFS.G; s/
1 for each vertex u 2 G:V  fsg
2 u:color D WHITE
3 u:d D 1
4 u:� D NIL
5 s:color D GRAY
6 s:d D 0
7 s:� D NIL
8 Q D ;
9 ENQUEUE.Q; s/
10 while Q ¤ ;
11 u D DEQUEUE.Q/
12 for each vertex v in G:AdjŒu� // search the neighbors of u
13 if v:color = = WHITE // is v being discovered now?
14 v:color D GRAY
15 v:d D u:d C 1
16 v:� D u
17 ENQUEUE.Q; v/ // v is now on the frontier
18 u:color D BLACK // u is now behind the frontier 
*/

// #include <iostream>
// #include <vector>
// #include <map>
// #include <queue>
// #include <climits>

// using namespace std;

// #define INF INT_MAX / 2

// enum Color { WHITE, GRAY, BLACK };

// class Vertex {
// public:
//     char label;
//     Color color;
//     int distance;
//     Vertex* ancestor;

//     Vertex(char label) {
//         this->label = label;
//         this->color = WHITE;
//         this->distance = INF;
//         this->ancestor = NULL;
//     }
// };

// class Graph {
// private:
//     map<char, Vertex> labelToVertex;

// public:
//     vector<Vertex> vertices;
//     map<char, vector<Vertex>> adj;

//     void addVertex(char label) {
//         Vertex v = Vertex(label);
//         labelToVertex[label] = v;
//         vertices.push_back(v);
//     }

//     void addEdge(char startLabel, char endLabel) {
//         Vertex& startVertex = labelToVertex[startLabel];
//         Vertex& endVertex = labelToVertex[endLabel];
//         adj[startLabel].push_back(endVertex);
//         adj[endLabel].push_back(startVertex);
//     }

//     Vertex& getVertexByLabel(char label) {
//         return labelToVertex[label];
//     }
// };

// void bfs(Graph& G, Vertex& source) {
//     source.color = GRAY;
//     source.distance = 0;
//     source.ancestor = nullptr;
//     queue<Vertex*> q;
//     q.push(&source);
//     while (!q.empty()) {
//         Vertex* u = q.front();
//         q.pop();
//         for (Vertex& v : G.adj[u->label]) {
//             if (v.color == WHITE) {
//                 v.color = GRAY;
//                 v.distance = u->distance + 1;
//                 v.ancestor = u;
//                 q.push(&v);
//             }
//         }

//         u->color = BLACK;
//     }
// }

// int main() {
//     int n, e;
//     char label;
//     cout << "Enter the number of nodes: ";
//     cin >> n;
//     cout << "Enter the node labels: ";
//     Graph G;
//     for (int i = 0; i < n; i++) {
//         cin >> label;
//         G.addVertex(label);
//     }

//     cout << "Enter the number of edges: ";
//     cin >> e;
//     char startEdgeLabel, endEdgeLabel;
//     for (int i = 0; i < e; i++) {
//         cout << "Enter the edge endpoints: ";
//         cin >> startEdgeLabel >> endEdgeLabel;
//         G.addEdge(startEdgeLabel, endEdgeLabel);
//     }

//     cout << "Enter the source label: ";
//     char sourceLabel;
//     cin >> sourceLabel;
//     bfs(G, G.getVertexByLabel(sourceLabel));

//     for (const Vertex& v : G.vertices) {
//         cout << "Vertex: " << v.label << ", has distance: " << v.distance << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX / 2

enum Color { WHITE, GRAY, BLACK };

class Vertex {
public:
    char label;
    Color color;
    int distance;
    Vertex* ancestor;

    Vertex(char label) {
        this->label = label;
        this->color = WHITE;
        this->distance = INF;
        this->ancestor = nullptr;
    }
};

class Graph {
private:
    map<char, Vertex*> labelToVertex; // Store pointers to Vertex objects

public:
    vector<Vertex*> vertices; // Store pointers to Vertex objects
    map<char, vector<Vertex*>> adj; // Store pointers to Vertex objects

    void addVertex(char label) {
        Vertex* v = new Vertex(label); // Create a new Vertex object dynamically
        labelToVertex[label] = v;
        vertices.push_back(v);
    }

    void addEdge(char startLabel, char endLabel) {
        Vertex* startVertex = labelToVertex[startLabel];
        Vertex* endVertex = labelToVertex[endLabel];
        adj[startLabel].push_back(endVertex);
        adj[endLabel].push_back(startVertex);
    }

    Vertex* getVertexByLabel(char label) {
        return labelToVertex[label];
    }
};

void bfs(Graph& G, Vertex* source) {
    source->color = GRAY;
    source->distance = 0;
    source->ancestor = nullptr;
    queue<Vertex*> q;
    q.push(source);
    while (!q.empty()) {
        Vertex* u = q.front();
        q.pop();
        for (Vertex* v : G.adj[u->label]) {
            if (v->color == WHITE) {
                v->color = GRAY;
                v->distance = u->distance + 1;
                v->ancestor = u;
                q.push(v);
            }
        }

        u->color = BLACK;
    }
}

int main() {
    int n, e;
    char label;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the node labels: ";
    Graph G;
    for (int i = 0; i < n; i++) {
        cin >> label;
        G.addVertex(label);
    }

    cout << "Enter the number of edges: ";
    cin >> e;
    char startEdgeLabel, endEdgeLabel;
    for (int i = 0; i < e; i++) {
        cout << "Enter the edge endpoints: ";
        cin >> startEdgeLabel >> endEdgeLabel;
        G.addEdge(startEdgeLabel, endEdgeLabel);
    }

    cout << "Enter the source label: ";
    char sourceLabel;
    cin >> sourceLabel;
    bfs(G, G.getVertexByLabel(sourceLabel));

    for (const Vertex* v : G.vertices) {
        cout << "Vertex: " << v->label << ", has distance: " << v->distance << endl;
    }

    // Clean up dynamically allocated Vertex objects
    for (const Vertex* v : G.vertices) {
        delete v;
    }

    return 0;
}
