package Graphs;

import java.util.Iterator;
import java.util.LinkedList;

// This class represents a directed graph using adjacency list
class Graph{
	private int V;	//N. of vertices
	private LinkedList<Integer> adj[];	//Adjacency list
	
	// Constructor
	Graph(int v){
		V = v;
		adj = new LinkedList[v];
		for (int i = 0; i < v; ++i){
			adj[i] = new LinkedList();
		}
	}
	
	// Function to add an edge into the graph
	void addEdge(int v, int w){
		adj[v].add(w);
	}
	
	// Print BFS transeversal from a give source s
	void BFS(int s){
		
		// Mark all the vertices as not visited (By default set as false)
		boolean visited[] = new boolean[V];
		
		// Create a queue for BFS 
		LinkedList <Integer> queue = new LinkedList<Integer>();
		
		// Mark the current node as visited and enqueue it
		visited[s] = true;
		queue.add(s);
		
		while(queue.size() != 0){
			
			// Dequeue a vertex from queue and print it 
			s = queue.poll();
			System.out.print(s + " ");
			
			// Get all adjacent vertices o the dequeued vertex s
			// If a adjacent has not been visited, then mark it visited and enqueue it
			Iterator<Integer> i = adj[s].listIterator();
			while(i.hasNext()){
				int n = i.next();
				if(!visited[n]){
					visited[n] = true;
					queue.add(n);
				}
			}
		}
	}
}


public class Breadh_First_Search {
	public static void main (String args[]){
		
		// Create a graph 
		Graph g = new Graph(4);
		
		// Add edges 
		g.addEdge(0, 1);
		g.addEdge(0, 2);
		g.addEdge(1, 2);
		g.addEdge(2, 0);
		g.addEdge(2, 3);
		g.addEdge(3, 3);
		
		System.out.print("Starting from vertex 2: ");
		g.BFS(2);
	}
}
