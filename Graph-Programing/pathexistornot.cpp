/*#include <queue>
using namespace std;

typedef pair<int,int> ipair;

int main() {
	//code
	
	int N;
	cin>>N;
	int i,j;
	int sr,sc,der,dec;
	int graph[N][N];
	bool vis[N][N];

	queue<ipair> pq;
	for(int i=0;i<N;i++){
	    for(int j=0;j<N;j++){
	        cin>>graph[i][j];
	        vis[i][j]=false;
	    }
	}
	for(int i=0;i<N;i++){
	    for(int j=0;j<N;j++){
	        if(graph[i][j]==1){
	            sr=i;
	            sc=j;
	        }
	        if(graph[i][j]==2){
	            der=i;
	            dec=j;
	        }
	       
	    }
	}
	int dr[4]={-1,1,0,0};
	int dc[4]={0,0,-1,1};
	
	pq.push(make_pair(sr,sc));
	while(!pq.empty()){
	    int r=pq.front().first;
	    int c=pq.front().second;
	    pq.pop();
	    vis[r][c]=true;
	    for(int i=0;i<4;i++){
	        int rr=r+dr[i];
	        int cc=c+dc[i];
	        if(rr<0 or cc<0)continue;
	        if(rr>=N or cc>=N)continue;
	        if(graph[rr][cc] and !vis[rr][cc]){
	            pq.push(make_pair(rr,cc));
	        }
	        
	        
	    }
	}
	cout<<vis[der][dec]<<"\n";

	return 0;
}













*/

using namespace std;
int mat[30][30];
int vis[30][30];

bool safe(int x,int y,int n){
    return x>=0 && x<n && y>=0 && y<n;
}
void dfs(int x,int y,int n,int &ans){
    int row[]={-1,0,0,1};
    int col[]={0,-1,1,0};
    vis[x][y]=1;
    if(mat[x][y]==2){
        ans=1;
        return;
    }
    for(int k=0;k<4;k++){
        if(safe(x+row[k],y+col[k],n) && vis[x+row[k]][y+col[k]]==0 && mat[x+row[k]][y+col[k]]!=0 && ans==0){
            dfs(x+row[k],y+col[k],n,ans);
        }
    }
}
int main()
 {
	
	    int n,i,j,x,y,ans=0;
	    cin>>n;
	    memset(vis,0,sizeof(vis));
	    memset(mat,0,sizeof(mat));
	    for(i=0;i<n;i++){
	        for(j=0;j<n;j++){
	            cin>>mat[i][j];
	            if(mat[i][j]==1){
	                x=i,y=j;
	            }
	        }
	    }
	    dfs(x,y,n,ans);
	    cout<<ans<<endl;
	    
	
	return 0;
}