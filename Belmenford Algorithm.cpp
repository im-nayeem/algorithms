#include<bits/stdc++.h>
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
//Shortest path algorithm that can detect negative cycle
// complexity O(|v|*|E|)
void Belmenford(vector<pii>&graph,vector<vector<int>>&cost,int node,int x,int y)
{
	vector<int>par(node+1,0); //vector containing parent of another node

	vector<int>dis(node+1,INT_MAX); // distance of a node from source node
	dis[x]=0;
	for(int i=1;i<node;i++) // relax all the edges for node-1 times or |v|-1 times
	{
		for(auto temp:graph)
		{
			int u=temp.first;
			int v=temp.second;
			if(dis[u]!=INT_MAX && dis[u]+cost[u][v]<dis[v])
				{
					dis[v]=dis[u]+cost[u][v];
					par[v]=u;
				}
		}
	
	}
	for(auto temp:graph) // if graph can be relaxed after node-1 times then it has negative cycle
	{
		int u=temp.first;
		int v=temp.second;
		if(dis[u]!=INT_MAX && dis[u]+cost[u][v]<dis[v])
			{
				cout<<"Negative cycle detected"<<endl;
				return;
			}
	}

	cout<<(dis[y]==INT_MAX?-1:dis[y])<<" "<<par[y]<<endl;

}
int main()
{
    fast; 
    int node,edge;
    cin>>node>>edge;

    vector<pii>graph(edge);
    vector<vector<int>> cost(node+1,vector<int>(node+1));
    for(int i=0;i<edge;i++)
    {
    	int u,v,w;
    	cin>>u>>v>>w;
    	graph.push_back(make_pair(u,v));
    	cost[u][v]=w;
    }
    int u,v;
    cin>>u>>v;
    Belmenford(graph,cost,node,u,v);


}