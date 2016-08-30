#include<iostream>
#include<vector>
#include<string.h>
#define NIL -1
using namespace std;
vector<int>v[1000];
bool visited[1000];
int parent[1000];
int disc[1000];
int low[1000];
bool apt[1000];
void dfs(int u)
{
	static int time=0;
	visited[u]=true;
	int child=0;
	disc[u]=low[u]=++time;
	for(int j=0;j<v[u].size();j++)
	{
		if(!visited[v[u][j]])
		{
			child++;
			parent[v[u][j]]=u;
			dfs(v[u][j]);
			low[u]=min(low[u],low[v[u][j]]);
			if(parent[u]==NIL&&child>1)
			apt[u]=true;
			if(parent[u]!=NIL&&low[v[u][j]]>=disc[u])
			apt[u]=true;
		}
		else if(v[u][j]!=parent[u])
		low[u]=min(low[u],disc[v[u][j]]);
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<1000;i++)
	v[i].clear();
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	memset(visited,false,sizeof(visited));
	memset(parent,NIL,sizeof(parent));
	memset(low,0,sizeof(low));
	memset(disc,0,sizeof(disc));
	memset(apt,false,sizeof(apt));
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		dfs(i);
	}
	for(int i=0;i<n;i++)
	{
		if(apt[i])
		cout<<i<<endl;
	}
}
