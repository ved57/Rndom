// Detect cycle in a graph using Graph coloring
/* Reference:
 * http://www.geeksforgeeks.org/detect-cycle-in-a-graph/
 * https://www.youtube.com/watch?v=rKQaZuoUR4M
 * http://www.geeksforgeeks.org/detect-cycle-direct-graph-using-colors/
 *
 */


#include <iostream>
#include <climits>
#include <vector>
#include <list>
#include <deque>
using namespace std;



class Graph{
	int V;
	vector<list<int> > adjList;
	enum color{
		WHITE, //not processed
		GRAY, //being processed
		BLACK //completely processed
	};
	vector<color> vecColor;
public:
	Graph(int Ver):V(Ver),adjList(V),vecColor(V){
	}

	void addEdge(int src, int des)
	{
		adjList[src].push_back(des);
	}

	bool hasCycle()
	{
		//Initialize all colour to white
		for (int i=0;i<V;i++)
		{
			vecColor[i]= WHITE;
		}

		//Conduct DFS for all WHITE nodes
		for(int i=0;i<V;i++)
		{
			if (vecColor[i]==WHITE)
			{
				//Do dfs on this node
				if (DFS_for_detecting_cycle(i))
				{
					return true;
				}
			}
		}
		return false;
	}

	//return true if cycle is detected in the graph
	bool DFS_for_detecting_cycle(int i)
	{
		vecColor[i]=GRAY;
		list<int>::iterator it;
		for (it=adjList[i].begin();it!=adjList[i].end();++it)
		{
			//if neighbour is already black don't dfs
			if (vecColor[*it]==BLACK)
			{

			}
			//else if neighbour is in gray then cycle
			else if (vecColor[*it] == GRAY)
			{
				return true;
			}

			//else if neighbour is in white then do dfs
			else if (vecColor[*it] == WHITE)
			{
				if (DFS_for_detecting_cycle(*it))
				{
					return true;
				}
			}
		}
		//All the neighbour nodes are processed
		vecColor[i]= BLACK;
		return false;
	}

};


void test_case_1()
{
	 // Create a graph given in the above diagram
	    Graph g(4);
	    g.addEdge(0, 1);
	    g.addEdge(0, 2);
	    g.addEdge(1, 2);
	    g.addEdge(2, 0);
	    g.addEdge(2, 3);
	    g.addEdge(3, 3);
	    cout<<"\n Does the graph has cycle "<<g.hasCycle();
}


//http://d1gjlxt8vb0knt.cloudfront.net//wp-content/uploads/DFS.jpg
void test_case_2()
{
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(3,0);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(5,3);
	cout<<"\n Does the graph has cycle "<<g.hasCycle();
}



int main()
{
	test_case_1();
	test_case_2();
	return 0;
}
