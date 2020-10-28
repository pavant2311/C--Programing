#include <bits/stdc++.h>
using namespace std;

int cyc(int v,vector<bool>&vis,vector<bool>&st,vector<int>adj[])
{
    if(!vis[v])
    {
        vis[v]=true;
        st[v]=true;
        vector<int>&m=adj[v];
        for(int i=0;i<m.size();i++)
        {
            if(!vis[m[i]] )
            {
            if(cyc(m[i],vis,st,adj)==1)
            return 1;
            }
            else if(st[m[i]])
            return 1;
        }
        st[v]=false;
	}
        return 0;   
}
int isCyclic(int V, vector<int> adj[])
{
    vector<bool>vis(V,false);
    vector<bool>st(V,false);
    for(int i=0;i<V;i++)
    {
        if(cyc(i,vis,st,adj)==1)
        return 1;
    }
    return 0;
}

int main()
{
	int v, e;
    cin >> v >> e;	    
	vector<int> adj[v];
	  
    for(int i =0;i<e;i++)
    {
     	int u, v; 
     	cin >> u >> v;
     	adj[u].push_back(v);
	}

   if(isCyclic(v,adj)==1)
    {
          cout<<"Graph has a cycle"<<endl;
    }
    else
         cout<<"Graph has a No cycle"<<endl;


	   return 0;
}