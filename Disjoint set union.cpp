#include<bits/stdc++.h>
#define ll long long
#define PI acos(-1.0)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define tc int t;cin>>t;while(t--)
#define endl "\n"
using namespace std;
class DisjointSetUnion
{
	vector<int>set;
	vector<int>size;
public:
	DisjointSetUnion(int n)
	{
		set.resize(n);
		size.resize(n);
		for(int i=0;i<n;i++)
			{
				set[i]=i;
				size[i]=1;
			}
	}
	int root(int v)
	{

		while(set[v]!=v)
		{
			set[v]=set[set[v]]; //path compression while finding the root
			v=set[v];
		}
		return v;
	}

	void weightedUnion(int u,int v)
	{
		int root_u=root(u);
		int root_v=root(v);
		if(size[root_u]<size[root_v])
		{
			set[root_u]=set[root_v];
			size[root_v]+=size[root_u];
		}
		else
		{
			set[root_v]=set[root_u];
			size[root_u]+=size[root_v];
		}

	}
	bool findJoint(int u,int v)
	{
		if(root(u)==root(v))
			return true;
		else
			return false;
	
	}
};
int main()
{
    fast;
    int n,q;
    cin>>n>>q;
    DisjointSetUnion obj(n);
    while(q--)
    {
    	int t,u,v;
    	cin>>t>>u>>v;
    	if(t==0)
 			obj.weightedUnion(u,v);
    	if(t==1)
				cout<<obj.findJoint(u,v)<<endl;
    }



}
