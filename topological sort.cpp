#include<iostream>
#include<list>
#include<stack>
using namespace std;
class graph
{
	public:
	int v;
	list<int> *adj;
	graph(int v);
	void add_edge(int a,int b);
	void topologicalsort();
	void tsort(int v,bool visited,stack<int>&Stack)	
}
graph::graph(int v)
{
	this->v=v;
	adj=new list<int>[v];
}
void graph::add_edge(int a,int b)
{
	adj[a].push_back(b);
}
void graph::topologicalsort()
{
	stack<int>Stack;
	bool *visited=new bool[v];
	for (int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<v;i++)
	{
		if(!visited[i]==false)
		tsort(i,visited,Stack)
	}
	while(!Sta)
}
void graph::tsort(int v,bool visited,stck<int>&Stack)
{
	visited[v]=true;
	list<int>::iterator it;
	for (it=adj[v].begin();it!=adj[v].end();it++)
	{
		if(!visited[*it])
		{
			tsort(*it,visited,Stack)
		}
	}
	Stack.push(v);
}
