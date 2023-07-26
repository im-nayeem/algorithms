#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define PI acos(-1.0)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define tc int t;cin>>t;while(t--)
#define endl "\n"
using namespace std;
void prims(vector<vector<pair<int,int>>>&graph)
{

	priority_queue<pii,vector<pii>,greater<pii>>q; //min-heap

	vector<bool>mst(graph.size(),0);

	vector<int>w(graph.size(),INT_MAX);

	q.push(make_pair(0,1));

	w[1]=0;
	mst[1]=true;
	
	vector<int>par(graph.size(),-1);
	
	while(!q.empty())
	{
		// if(mst[q.top().second]==false)
		// 	cout<<par[q.top().second]<<"->"<<q.top().second<<" cost="<<q.top().first<<endl;

		int node=q.top().second;q.pop();
		mst[node]=true;

		for(auto u:graph[node])
		{
			int v=u.first;
			int weight=u.second;
			if(!mst[v] && w[v]>weight)
			{
				w[v]=weight;
				q.push(make_pair(w[v],v));
				par[v]=node;
			}
		}
	}
	for(int i=1;i<graph.size();i++)
        cout<<i<<" "<<par[i]<<endl;
}
int main()
{
    fast;
    int node,edge;
    cin>>node>>edge;
    vector<vector<pii>> graph(node+1);
    for(int i=0;i<edge;i++)
    {
    	int u,v,w;
    	cin>>u>>v>>w;
    	graph[u].push_back(make_pair(v,w));
    	graph[v].push_back(make_pair(u,w));
    }

    prims(graph);

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
