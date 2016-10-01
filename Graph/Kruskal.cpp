/*
 * Kruskal's algorithm - using edgelist
 */

#include <iostream>
using namespace std;

#include <vector>
#include <set>
#include <algorithm>

struct Edge {
	int src;
	int des;
	int wt;
	Edge(int s,int d,int w):src(s),des(d),wt(w){}
};

class edgeCompare{
public:
	bool operator() (Edge e1, Edge e2){
		return e1.wt<e2.wt;
	}
};

class Graph{
	vector<Edge> edgeList;
	unsigned int V;
public:
	Graph(int v, int e):V(v){
	}
	void addEdge(const Edge& edge)
	{
		edgeList.push_back(edge);
	}
	void addEdge(int src, int des, int wt){
		edgeList.push_back(Edge(src,des,wt));
	}

	bool insertAcyclicConnComp(set<int>& connComp, int src, int des)
	{
		//a cycle is formed only if both src and des are present
    pair<set<int>::iterator, bool>res1 = connComp.insert(src);
		pair<set<int>::iterator, bool>res2 = connComp.insert(des);    
		return res1.second || res2.second;
	}

	void KruskalMST()
	{
		//Step 1/3: sort the edges of the graph according to the wt
		edgeCompare oEdgeCompare;
		std::sort(edgeList.begin(),edgeList.end(),oEdgeCompare);

		//Step 2/3: Form acyclic graph
		vector<Edge> mstKruskal;
		set<int> connectedComponents;
		//2nd condn is optimization to prevent checking all edges
		for (unsigned int i=0;i<edgeList.size() && mstKruskal.size()<=V-1; i++)
		{
			if (insertAcyclicConnComp(connectedComponents,edgeList[i].src,edgeList[i].des))
			mstKruskal.push_back(edgeList[i]);
		}

		//Step 3/3: print mst
		for (unsigned int i=0;i<mstKruskal.size();i++)
		{
			cout<<"\n "<<mstKruskal[i].src<<" --> " <<mstKruskal[i].des<<" == "<<mstKruskal[i].wt;
		}
	}
};

// Driver program to test above functions
int main()
{
    /* Let us create following weighted graph
             10
        0--------1
        |  \     |
       6|   5\   |15
        |      \ |
        2--------3
            4       */
    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    Graph graph(V, E);
    // add edge 0-1
    graph.addEdge(0,1,10);
    // add edge 0-2
    graph.addEdge(0,2,6);
    // add edge 0-3
    graph.addEdge(0,3,5);
    // add edge 1-3
    graph.addEdge(1,3,15);
    // add edge 2-3
    graph.addEdge(2,3,4);
    graph.KruskalMST();
    return 0;
}
