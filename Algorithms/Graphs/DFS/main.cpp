#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;

class Graph{
    int V;
    list <int> *adj;
    void DFS_visit(int v, bool visited[]);

public:
    Graph(int V);
    void addEdge(int v,int w);
    void DFS(int v);
};

Graph::Graph(int V){
    this -> V =V;
    adj = new list <int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::DFS_visit(int v, bool visited[]){

    visited[v] = true;
    printf("%d ", v);

    list <int>::iterator i;
    for(i =adj[v].begin(); i != adj[v].end(); ++i){
        if(!visited[*i]){
            DFS_visit(*i, visited);
        }
    }
}

void Graph::DFS(int v){
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++){
        visited[i] = false;
    }
    DFS_visit(v, visited);
}

int main()
{
	int v, a, b, s;
    scanf("%d", &v);
    Graph g(v);

    while(scanf("%d %d", &a, &b), a != -1){
    	g.addEdge(a, b);
    }

	scanf("%d", &s);
    g.DFS(s);

    return 0;
}
