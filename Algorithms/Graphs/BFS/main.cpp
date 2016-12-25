#include <stdio.h>
#include <list>
#include <iostream>

using namespace std;

class Graph{
	int vertices;
    list <int> *adj;

public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void BFS(int s);
};

Graph::Graph(int vertices){
    this->vertices = vertices;
    adj = new list<int>[vertices];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::BFS(int s){

    bool *visited = new bool[vertices];
    for(int i = 0; i < vertices; i++){
        visited[i] = false;
    }

    list<int> queue;
    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;

    while(!queue.empty()){

        s = queue.front();
        printf("%d ", s);
        queue.pop_front();

        for(i = adj[s].begin(); i != adj[s].end(); ++i){
            if(!visited[*i]){
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main(){

    int v, a, b, s;

    scanf("%d", &v);
    Graph g(v);


	while(scanf("%d %d", &a, &b), a != -1){
		g.addEdge(a, b);
	}

    scanf("%d", &s);
    g.BFS(s);

    return 0;
}








