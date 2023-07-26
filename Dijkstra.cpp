#include<bits/stdc++.h>
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define tc int t;cin>>t;while(t--)
using namespace std;
//Shortest path algorithm that can't detect negative cycle
//Complexity O(|V|log|v|+|E|) or O(|v|log|v|)

void dijkstra(vector<int>graph[],vector<vector<int>>&cost,int u,int v)
{
	vector<int>dis(cost.size(),INT_MAX); // distance of a node from source node

	dis[u]=0; // distance for source node is 0

	priority_queue<pii,vector<pii>,greater<pii>>pq;
			 //sort the nodes according to their distance from source node

	pq.push(make_pair(0,u)); 

	while(!pq.empty()) // relax edge until there is no edge in queue
	{
		int node=pq.top().second;pq.pop(); 
			// extract the node with minimum distance from source node
		cout<<node<<" "<<dis[node]<<endl;

		for(auto x:graph[node]) //relax all the edge adjacent to the extracted node from queue
			if(dis[node]!=INT_MAX && dis[node]+cost[node][x]<dis[x])
			{
				dis[x]=dis[node]+cost[node][x];
				pq.push(make_pair(dis[x],x)); //push the node in queue with relaxed path distance
			}
	}
	
	cout<<(dis[v]==INT_MAX?-1:dis[v])<<endl;
}
int main()
{
    fast; 
    int node,edge;
    cin>>node>>edge;
    vector<int>graph[node+1];
    vector<vector<int>>cost(node+1,vector<int>(node+1));
    for(int i=0;i<edge;i++)
    {
    	int u,v,w;
    	cin>>u>>v>>w;
    	graph[u].push_back(v);
        graph[v].push_back(u);
        cost[u][v]=w;
        cost[v][u]=w;
    
    }

    // int u=1,v=node;
    int u,v;
    cin>>u>>v;
    dijkstra(graph,cost,u,v);



}