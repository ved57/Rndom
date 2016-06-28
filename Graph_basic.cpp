
/*
This file should consist of
1) Graph Representation
2) DFS
3) BFS
4) Djikstra
5) Bellman
6) Prim
7) Kruskal
8) A*
9) Print a graph
*/
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <queue>
#include <stack>
typedef int Nbr;
typedef int Wt;

class Graph
{
	int V;
	vector< map<Nbr,Wt> > adjList;
	bool bDirected;
public:
	Graph(int vertices,bool directed=false):V(vertices), adjList(V), bDirected(directed)
	{
	}

	void addEdge(int src, int des, int wt=0)
	{
		pair<Nbr,Wt> adjNode = make_pair(des,wt);
		adjList[src].insert(adjNode);

		if (!bDirected)
		{
			pair<Nbr,Wt> adjNode2 = make_pair(src,wt);
			adjList[des].insert(adjNode2);
		}
	}

	void printGraph()
	{
		for (int i=0;i<adjList.size();++i)
		{
			cout<<"\n Neighbours of "<<i<<" are: ";
			map<Nbr,Wt>::iterator itAdjList;
			for (itAdjList = adjList[i].begin();itAdjList!=adjList[i].end();++itAdjList)
			{
				cout<<"\t "<<itAdjList->first;
			}
		}
	}


	void DFS_RecursionHelper(bool *visited, int src)
	{
			//Find the neighbours of current node
		map<Nbr,Wt>::iterator itAdjList;
		for(itAdjList=adjList[src].begin();itAdjList!=adjList[src].end();++itAdjList)
		{
			int neighbour = itAdjList->first;
			if (!visited[neighbour])
			{
				visited[neighbour] = true;
				cout<<"\t "<<neighbour;
				DFS_RecursionHelper(visited,neighbour);
			}
		}
	}

	void DFS (int src)
	{

   //Initialize the visited array
		bool visited[V];
		for (int i=0;i<V;i++)
		{
			visited[i] = false;
		}
		visited[src] = true;
		cout<<"\t "<<src;
		DFS_RecursionHelper(visited,src);
	}

	void DFS_NonRecursive(int src)
	{
		cout<<"\n Non recursive DFS called ";
		bool visited[V];
		for (int i=0;i<V;i++)
			visited[i] = false;
		visited[src] = true;
		stack<int> s;
		s.push(src);
		while(!s.empty())
		{
			src = s.top();
			s.pop();
			cout<<"\t "<<src;
			map<Nbr,Wt>::iterator it;
			for (it=adjList[src].begin();it!=adjList[src].end();++it)
			{				
				if(!visited[it->first])
				{
					visited[it->first]=true;					
					s.push(it->first);					
				}
			}
		}
	}


void BFS_NonRecursive(int src)
	{
		cout<<"\n Non recursive DFS called ";
		bool visited[V];
		for (int i=0;i<V;i++)
			visited[i] = false;
		visited[src] = true;
		queue<int> q;
		q.push(src);
		while(!q.empty())
		{
			src = q.front();
			q.pop();
			cout<<"\t "<<src;
			map<Nbr,Wt>::iterator it;
			for (it=adjList[src].begin();it!=adjList[src].end();++it)
			{				
				if(!visited[it->first])
				{
					visited[it->first]=true;					
					q.push(it->first);					
				}
			}
		}
	}
};


int main(int argc, char const *argv[])
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	g.printGraph();
	cout<<endl;
	g.DFS(0);

	cout<<endl;
	cout<<endl;
	g.DFS_NonRecursive(0);
	/* code */
	return 0;
}