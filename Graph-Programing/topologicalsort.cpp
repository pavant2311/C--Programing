#include<bits/stdc++.h>
using namespace std;

bool check(int V, int* res, vector<int> adj[]){
    bool flag =true;
    for(int i=0;i<V && flag;i++)
    {
        int n=adj[res[i]].size();
        for(auto j : adj[res[i]])
        {
            for(int k=i+1;k<V;k++)
            {
                if(res[k]==j )
                    n--;
            }
        }
        if(n!=0)
            flag =false;
    }
    if(flag==false)
        return 0;
          return 1;
}

void dfs(int v,vector<int> adj[],vector<bool>& vis,stack<int>& s)
{
    vis[v]=true;
    //vector<int>&m=adj[v];
    //for(int i=0;i<m.size();i++)
    {
        if(!vis[m[i]])
        dfs(m[i],adj,vis,s);
    }
    s.push(v);
}

int* topoSort(int V, vector<int> adj[])
{
vector<bool>vis(V,false);
stack<int>s;
for(int i=0;i<V;i++)
{
    if(!vis[i])
    dfs(i,adj,vis,s);
}
int n=s.size();
int *a=new int[n];
int i=0;
while(!s.empty())
{
    a[i]=s.top();
    cout<<s.top()<<" ";
    s.pop();
    i++;
}
return a;
}


int main()
{
    int N,E;
        cin>>E>>N;
        int u,v;
        
        vector<int> adj[N];
        
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }
    
        int *res = topoSort(N, adj);
        cout<<"\n";
            cout<<check(N, res, adj)<<endl;
         
}
