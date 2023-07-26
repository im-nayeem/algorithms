#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int u,v,w;
	
};
bool cmp(const edge& a,const edge& b)
{
		return a.w<b.w;
}
int find(vector<int>&par,int  v)
{
	if(par[v]==v)
		return v;
	return find(par,par[par[v]]);

}
void kruskal(vector<edge>&graph,int node)
{
	
	vector<int>par(node+1);

	for(int i=0;i<par.size();i++)
		par[i]=i;

	int cost=0;
	for(int i=0;i<graph.size();i++)
	{
		int root_u=find(par,graph[i].u);
		int root_v=find(par,graph[i].v);
		if(root_u!=root_v)
		{
			par[root_u]=root_v;
			cout<<graph[i].u<<"->"<<graph[i].v<<endl;
			cost+=graph[i].w;
			
		}

	}
	cout<<"Total Cost: "<<cost<<endl;

}
int main()
{
  
    int node,E;
    cin>>node>>E;
	vector<edge>graph;

	for(int i=0;i<E;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		graph.push_back({u,v,w});

	} 
	sort(graph.begin(),graph.end(),cmp);

	kruskal(graph,node);




}
// 8 11
// 1 2 4 
// 1 5 2 
// 1 4 10
// 2 3 18
// 2 4 8 
// 4 5 5 
// 4 3 11
// 4 7 11
// 4 8 9 
// 7 6 1 
// 6 8 2 