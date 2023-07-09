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

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>
#include <fstream>

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

void printPath(Graph& G, Vertex* s, Vertex* v) {
    if (v->label == s->label) {
        printf("%c\n", v->label);
    } else if (v->ancestor == nullptr) {
        printf("no path exists between %c and %c", s->label, v->label);
    } else {
        printPath(G, s, v->ancestor);
        printf("%c\n", v->label);
    }
}

template <typename inputType>
void getInput(ifstream& inFile, inputType& var) {
    bool success = bool(inFile >> var);
    if (!success) {
        cout<<"input failed: may have reached end of file"<<endl;
    }
}

int main() {
    ifstream inFile;
    ofstream outFile;
    inFile.open("./inputs/bfs1.txt");
    if (!inFile) {
        cout << "Unable to open input file";
        exit(1);
    }

    outFile.open("./outputs/bfs1.txt");
    if (!outFile) {
        cout << "Unable to open output file";
        exit(1);
    }

    int n, e;
    char label;
    Graph G;
    getInput<int>(inFile, n);
    for (int i = 0; i < n; i++) {
        inFile >> label;
        cout<<"label is: "<<label<<endl;
        G.addVertex(label);
    }

    getInput<int>(inFile, e);
    cout<<"number of edges is:"<<e<<endl;
    char startEdgeLabel, endEdgeLabel;
    for (int i = 0; i < e; i++) {
        getInput<char>(inFile, startEdgeLabel);
        getInput<char>(inFile, endEdgeLabel);
        cout<<"edge ends are: "<<startEdgeLabel<<" "<<endEdgeLabel<<endl;
        G.addEdge(startEdgeLabel, endEdgeLabel);
    }

    char sourceLabel;
    getInput<char>(inFile, sourceLabel);
    inFile.close();

    bfs(G, G.getVertexByLabel(sourceLabel));
    for (const Vertex* v : G.vertices) {
        cout << "Vertex: " << v->label << ", has distance: " << v->distance << endl;
        outFile << "Vertex: " << v->label << ", has distance: " << v->distance << endl;
    }

    outFile.close();
    cout<<"printing path between s & z"<<endl;
    printPath(G, G.getVertexByLabel('s'), G.getVertexByLabel('z'));
    for (const Vertex* v : G.vertices) {
        delete v;
    }

    return 0;
}
